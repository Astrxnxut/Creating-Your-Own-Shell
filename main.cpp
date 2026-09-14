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
       char command[256];
       strcpy(command, userInput.c_str());

       // Gets the first token
       char *token = strtok(command, "\t\n");

       // Continues getting tokens until none are left
       while (token !NULL)
       {
            if(debug)
            {
                cout << token << endl;
            }

            token = strtok(NULL, " \t\n");
       }

       

    }
    return 0;
}