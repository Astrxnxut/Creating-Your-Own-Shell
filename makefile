myshell: main.o param.o
	g++ main.o param.o -o myshell

main.o: main.cpp
	g++ -c main.cpp

param.o: param.hpp param.cpp
	g++ -c param.cpp

clean:
	rm *.o myshell