#include "param.hpp"
#include "parse.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>

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

        //Clean up any background processes that have finished
        while(waitpid(-1, NULL, WNOHANG) > 0){
        }

        //Shell prompt
        cout << "$$$ ";

        getline(cin,userInput);

        /*
        Checks to see if user input is equal to "exit",
        if so, exit the program
        */
        if(userInput == "exit"){
            // Wait for all remaining child processes before exiting
            while(wait(NULL) > 0){
            }

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

        //Parse the user input and save the data into the Param class
        //Update - Parsing functionality moved to parse.cpp
        bool validCommand = parse(command, param);

        //Testing that all of our tokens are saved
        if(validCommand && debug){
            param.printParams();
        }

        //Create a child process to execute the command
        if(validCommand && param.getArgc() > 0){
            pid_t pid = fork();

        if(pid < 0){
            cout << "Error: Failed to create child process." << endl;
        }
        else if(pid == 0){
            //Redirect input if an input file was specified
            if(param.getInputRedirect() != nullptr){
                if(freopen(param.getInputRedirect(), "r", stdin) == NULL){
                    cout << "Error: Could not open input file." << endl;
                    exit(1);
                }
            }

            //Redirect output if an output file was specified
            if(param.getOutputRedirect() != nullptr){
                if(freopen(param.getOutputRedirect(), "w", stdout) == NULL){
                    cout << "Error: Could not open output file." << endl;
                    exit(1);
                }
            }

            //Child process executes the command
            execvp(param.getArgv()[0], param.getArgv());

            //Only reaches here if execvp fails
            cout << "Error: " + (string)param.getArgv()[0] + " is not a valid command." << endl;
            exit(1);
        }
        else{
            //Only wait for the child if it's not running in the background
            if(param.getBackground() == 0) {
                waitpid(pid, NULL, 0);
            }         
        }
    }        
        
        //Deallocate memory
        delete[] command;
        param.reset();
    }

    return 0;
}
