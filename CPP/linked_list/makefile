CC = g++
FLAGS = -std=c++11 -Wall -g

default: linked_list

$(default): linked_list.o 
	$(CC) linked_list.o -o linked_list.exe

linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp $(FLAGS)

clean:
	rm -f *.o *.exe *.out linked_list