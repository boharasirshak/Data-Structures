CC = g++
flags = -Wall -g -std=c++11

all: stack
default: stack

stack: stack.o
	$(CC) $(flags) -o stack stack.o

stack.o: stack.cpp
	$(CC) $(flags) -c stack.cpp

clean:
	rm -f *.o *.exe *.out stack