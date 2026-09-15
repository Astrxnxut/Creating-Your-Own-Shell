#include "param.hpp"

Param::Param(){
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    argumentCount = 0;
    background = 0;

    cout << "Param main constructor operational" << endl;
}

Param::~Param(){

}

void Param::reset(){
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
    for(int i = 0; i < argumentCount; ++i){
        
        cout << argumentVector[i] << " ";
    }
    cout << endl;
}