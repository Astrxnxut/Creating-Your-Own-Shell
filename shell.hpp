#ifndef SHELL_HPP
#define SHELL_HPP

#include "user_io.hpp"

class Shell{
    public:
        Shell();
        ~Shell();

        void start();

        int getArgc();
        char* getArgv();

        void setDebug(bool debug);
        bool getDebug();
    private:
        int argc;
        char *argv;
        bool debug;

};

#endif // SHELL_HPP