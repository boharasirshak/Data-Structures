CC = g++
flags = -Wall -g -std=c++11

all: queue
default: queue

queue: queue.o
	$(CC) $(flags) -o queue queue.o

queue.o: queue.cpp
	$(CC) $(flags) -c queue.cpp

clean:
	rm -f *.o *.exe *.out queue