#include "parse.hpp"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

/*
Moved command parsing functionality from myshell.cpp
into parse.cpp 
*/

bool parse(char* command, Param& param){
    char* delimiters = (char*)"\t\n ";

    //Checking for background and that it is the last char in the line
    bool scrappingCommand = false;

    //Changed i to size_t to match the return type of strlen()
    for(size_t i = 0; i < strlen(command); ++i){
        if(command[i] == '&' && i + 1 != strlen(command)){
            scrappingCommand = true;
            cout << "Error: Background indicator found, but not as the last character." << endl;
            cout << "Scrapping Command" << endl;
        }
    }

    if(!scrappingCommand){
        // Gets the first token
        char* token = strtok(command, delimiters);

        // Continues getting tokens until none are left
        while (token != NULL){

            //We will not allow spaces after our input and output redirect

            //Checks for input redirection
            if(token[0] == '<'){
                //Means there is only the identifier and no file name after it
                if(strlen(token) == 1){
                    cout << "Error: input redirect indicator identified, but no file name." << endl;
                }
                else{
                    param.setInputRedirect(token + 1);
                }
            }

            //Checks for output redirection
            else if(token[0] == '>'){
                //Means there is only the identifier and no file name after it
                if(strlen(token) == 1){
                    cout << "Error: output redirect indicator identified, but no file name." << endl;
                }
                else{
                    param.setOutputRedirect(token + 1);
                }
            }

            //Checking for backgrounding
            else if(token[0] == '&'){
                param.setBackground(1);
            }
            else{
                //If it's not an input, output redirect or a background sepcifier, we will save the token normally
                param.addToken(token);
            }

            //Needs to stay here or will cause infinite loop
            token = strtok(NULL, " \t\n");
        }
    }

    return !scrappingCommand;
}