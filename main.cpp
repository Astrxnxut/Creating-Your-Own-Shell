#include "param.hpp"
#include <iostream>
#include <string>
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

       

    }
    return 0;
}