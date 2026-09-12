#ifndef USER_IO_HPP
#define USER_IO_HPP

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class User_IO{
    public:
        User_IO();
        ~User_IO();

        char* getTokens(string userInput);
        string getUserInput();

        void printDebugMessage(string userInput);

    private:
        void sendShellPrompt();
};

#endif // USER_IO_HPP