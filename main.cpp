#include "param.hpp"
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char *argv[]){
    Param param;
    bool debug = false;
    char* delimiters = "\t\n ";

    if (argc > 1 && string(argv[1]) == "-Debug"){
            debug = true;
        }

    //Testing debug mode
    cout << "Debug mode " << (debug ? "is " : "is not ") << "active." << endl;

    while(true){
        string userInput;

        //Shell prompt
        cout << "$$$ ";

        getline(cin,userInput);

        /*
        Checks to see if user input is equal to "exit",
        if so, exit the program
        */
       if(userInput == "exit"){
            break;
       }

       // Copy the C++ string into a C-style string

       /*
       I'm not sure if there was a reason you had 256 here,
       but I made it more space efficient
       */

       //Allocate enough space for the string plus the null terminator
       char* command = new char[userInput.length() + 1];

       strcpy(command, userInput.c_str());

       //Checking for background and that it is the last char in the line
       bool scrappingCommand = false;

       for(int i = 0; i < strlen(command); ++i){
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

                        //Test for input redirect
                        cout << "Testing saving input redirection using setInputRedirect() method." << endl;
                        cout << endl;
                        cout << "Token to be saved: " << token + 1 << endl;
                        cout << "Input Redirect Value: " << param.getInputRedirect() << endl;
                        cout << endl << endl;
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

                    //Test for input redirect
                    cout << "Testing saving output redirection using setOutputRedirect() method." << endl;
                    cout << endl;
                    cout << "Token to be saved: " << token + 1 << endl;
                    cout << "Output Redirect Value: " << param.getOutputRedirect() << endl;
                    cout << endl << endl;
                    }
                }
                //Checking for backgrounding
                else if(token[0] == '&'){
                    param.setBackground(1);

                    cout << "Testing saving the background value." << endl << endl;
                    cout << "Background should be 1" << endl;
                    cout << "Actual background value: " << param.getBackground() << endl;
                }
                else{
                    //If it's not an input, output redirect or a background sepcifier, we will save the token normally
                    param.addToken(token);

                    //Testing adding tokens to the argumentVector
                    if(param.getArgc() == 1){
                        cout << "Testing adding tokens to argv using addToken() method." << endl;
                        cout << endl;
                    }

                    cout << "Token to be saved: " << token << endl;
                    cout << "Token array value: " << param.getArgv()[param.getArgc() - 1] << endl;
                    cout << endl;
                }

                //Needs to stay here or will cause infinite loop
                token = strtok(NULL, " \t\n");
            }    
            //Testing that all of our tokens are saved
            if(debug){
                //Im not sure if this is supposed to print the input output redirects so yea
                param.printParams();
            }
        }

        //Deallocate memory
        delete[] command;
        param.reset();
    }
    return 0;
}