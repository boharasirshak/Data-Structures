#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#endif

#include "vector"

struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next);
};

class LinkedList
{

public:
    LinkedList() = default;
    LinkedList(std::vector<int> &items);
    LinkedList(int items[], int size);
    ~LinkedList() = default;

    int size();
    void print();

    void PushBack(int data);
    void PushFront(int data);
    void ExtendBack(int items[], int size);
    void ExtendBack(std::vector<int> &items);
    void ExtendFront(int items[], int size);
    void ExtendFront(std::vector<int> &items);
    void PushAt(int index, int data);

private:
    Node *m_HeadNode = nullptr;
};