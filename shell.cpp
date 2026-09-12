#include "shell.hpp"

Shell::Shell(){
    debug = false;
    argc = 0;
}


Shell::~Shell(){

}

int Shell::getArgc(){
    return argc;
}

char* Shell::getArgv(){
    return argv;
}

void Shell::setDebug(bool debug){
    this->debug = debug;

    if(debug == true){
        cout << "Debug Mode is Active" << endl;
    }
    else{
        cout << "Debug Mode is Inactive" << endl;
    }
}

bool Shell::getDebug(){
    return debug;
}

void Shell::start(){
    /*
    Passes if the shell was started in debug mode,
    so the User_IO class can handle the debug messages
    */
    User_IO userIO;

    while(true){
        string userInput = userIO.getUserInput();

        if(userInput == "exit"){
            break;
        }

        if(getDebug() == true){
            userIO.printDebugMessage(userInput);
        }
    }
}