#include "param.hpp"
#include "parse.hpp"
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

        /*
        I'm not sure if there was a reason you had 256 here,
        but I made it more space efficient
        */

        //Allocate enough space for the string plus the null terminator
        char* command = new char[userInput.length() + 1];

        strcpy(command, userInput.c_str());

        //Parse the user input and save the data into the Param class
        //Updated: Parsing functionality moved to parse.cpp
        bool validCommand = parse(command, param);

        //Testing that all of our tokens are saved
        if(validCommand && debug){
            param.printParams();
        }

        //Deallocate memory
        delete[] command;
        param.reset();
    }

    return 0;
}