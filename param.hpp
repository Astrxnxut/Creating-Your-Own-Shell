#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32
#include <iostream>
using std::cout;
using std::endl;

class Param{
    public:
        Param();
        ~Param();
        int getArgc();
        char** getArgv();
        void printParams();

        void setArgc(int argc);
        void setBackground(int background);
        void setInputRedirect(char* inputRedirect);
        void setOutputRedirect(char* outputRedirect);

        char* getInputRedirect();
        char* getOutputRedirect();
        int getBackground();

        void addToken(char* token);
        void reset();
    private:
        char* inputRedirect;
        char* outputRedirect;
        int background;
        int argumentCount;
        char* argumentVector[MAXARGS];


};




#endif // PARAM_HPP