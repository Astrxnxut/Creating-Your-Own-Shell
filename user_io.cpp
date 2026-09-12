#include "user_io.hpp"

// char* USER_IO::getTokens(){

// }

User_IO::User_IO(){
    
}

User_IO::~User_IO(){
    
}

string User_IO::getUserInput(){
    //Prompts the user that it is ready to receive input
    sendShellPrompt();

    string userInput;
    //Gets the users input
    getline(cin,userInput);

    return userInput;
}

void User_IO::sendShellPrompt(){
    cout << "$$$ ";
}

void User_IO::printDebugMessage(string userInput){
    cout << "You entered: " << userInput << endl;
}