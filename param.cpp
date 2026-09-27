#include "param.hpp"

Param::Param(){
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    argumentCount = 0;
    background = 0;

    //Updated: Initialize all argumentVector values to nullptr
    for(int i = 0; i < MAXARGS; ++i){
        argumentVector[i] = nullptr;
    }
}

Param::~Param(){

}

void Param::reset(){
    //Updated: Reset input and output redirection for each new command
    inputRedirect = nullptr;
    outputRedirect = nullptr;

    argumentCount = 0;
    
    for(int i = 0; i < MAXARGS; ++i){
        argumentVector[i] = nullptr;
    }

    background = 0;
}

void Param::addToken(char* token){
    argumentVector[argumentCount] = token;
    ++argumentCount;
}

void Param::setBackground(int backgroundValue){
    this->background = backgroundValue;
}

int Param::getBackground(){
    return background;
}

void Param::setArgc(int argc){
    argumentCount = argc;
}

void Param::setInputRedirect(char* inputRedirect){
    this->inputRedirect = inputRedirect;
}

void Param::setOutputRedirect(char* outputRedirect){
    this->outputRedirect = outputRedirect;
}

char* Param::getInputRedirect(){
    return inputRedirect;
}

char* Param::getOutputRedirect(){
    return outputRedirect;
}

char** Param::getArgv(){
    return argumentVector;
}

int Param::getArgc(){
    return argumentCount;
}

void Param::printParams(){
    //Updated: Print all Param values when testing in Debug mode
    cout << "Argument Count: " << argumentCount << endl;

    cout << "Argument Vector: ";
    for(int i = 0; i < argumentCount; ++i){
        cout << argumentVector[i] << " ";
    }
    cout << endl;

    cout << "Input Redirect: ";
    if(inputRedirect != nullptr){
        cout << inputRedirect;
    }
    else{
        cout << "NULL";
    }
    cout << endl;

    cout << "Output Redirect: ";
    if(outputRedirect != nullptr){
        cout << outputRedirect;
    }
    else{
        cout << "NULL";
    }
    cout << endl;

    cout << "Background: " << background << endl;
}