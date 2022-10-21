CC = g++
FLAGS = -std=c++11 -Wall -g

default: linked_list

linked_list: linked_list.o 
	$(CC) linked_list.o -o linked_list

linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp $(FLAGS)

clean:
	rm *.o

remove:
	rm *.o linked_list