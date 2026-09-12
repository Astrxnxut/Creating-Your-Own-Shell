myshell: shell.o user_io.o myshell.o
	g++ shell.o user_io.o myshell.o -o myshell

myshell.o: myshell.cpp
	g++ -c myshell.cpp

shell.o: shell.hpp shell.cpp
	g++ -c shell.cpp

user_io.o: user_io.hpp user_io.cpp
	g++ -c user_io.cpp

clean:
	rm *.o myshell