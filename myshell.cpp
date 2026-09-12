#include "shell.hpp"

using namespace std;

int main(int argc, char *argv[]){

    Shell shell;
    
    //Check if the shell was started in debug mode
    if (argc > 1 && string(argv[1]) == "-Debug"){
        shell.setDebug(true);
    }

    shell.start();

    return 0;
}