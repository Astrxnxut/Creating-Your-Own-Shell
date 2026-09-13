#include "param.hpp"

Param::Param(){

}

Param::~Param(){

}

void Param::setBackground(int backgroundValue){
    this->background = background;
}

void Param::setArgc(int argc){
    argumentCount = argc;
}

void Param::setInputRedirect(){
    delete(inputRedirect);
}

void Param::setOutputRedirect(){

}