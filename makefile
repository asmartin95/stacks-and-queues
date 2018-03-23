all: project2.o

project2.o: menu.cpp stack.h queue.h
	g++ -std=c++11 -Wall menu.cpp stack.h queue.h -o a.out