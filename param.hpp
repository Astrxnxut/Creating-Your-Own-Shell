#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32
class Param{
    public:
        Param();
        ~Param();
        int getArgc();
        char* getArgv();
        void printParams();

        void setArgc(int argc);
        void setBackground(int background);
        void setInputRedirect();
        void setOutputRedirect();
    private:
        char* inputRedirect;
        char* outputRedirect;
        int background;
        int argumentCount;
        char* argumentVector[MAXARGS];


};




#endif // PARAM_HPP