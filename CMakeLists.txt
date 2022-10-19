cmake_minimum_required(VERSION 3.23)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(LinkedList)

add_executable(Data_Structures
        LinkedList/LinkedLists.cpp
        LinkedList/linkedlists.h)
