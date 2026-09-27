myshell: myshell.o param.o parse.o
	g++ -g -Wall myshell.o param.o parse.o -o myshell

myshell.o: myshell.cpp
	g++ -g -Wall -c myshell.cpp

param.o: param.hpp param.cpp
	g++ -g -Wall -c param.cpp

parse.o: parse.hpp parse.cpp
	g++ -g -Wall -c parse.cpp

clean:
	rm *.o myshell