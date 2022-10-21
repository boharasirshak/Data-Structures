#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#endif

#include "vector"

struct Node 
{
    int data;
    Node* next;
    Node(int data, Node* next);
};

class LinkedList 
{

public:
    LinkedList() = default;
    LinkedList(std::vector<int> items);

    ~LinkedList() = default;
    
    int size();
    void print();

    void PushBack(int data);
    void ExtendBack(int items[], int size);
    void PushFront(int data);
    void ExtendFront(int items[], int size);
    void PushAt(int index, int data);

private:
    Node* m_HeadNode = nullptr;
};