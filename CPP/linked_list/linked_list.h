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

#define THROW_IF_EMPTY_LIST(headNode)                                       \
    {                                                                       \
        if (headNode == nullptr)                                            \
        {                                                                   \
            throw std::invalid_argument("Empty list, fill the list first"); \
        }                                                                   \
    }

class LinkedList
{

public:
    LinkedList() = default;
    LinkedList(std::vector<int> &items);
    LinkedList(int items[], int size);
    ~LinkedList();

    int size();
    void Print();
    void Reverse();
    void ReverseR();
    

    void PushBack(int data);
    void PushFront(int data);
    void ExtendBack(int items[], int size);
    void ExtendBack(std::vector<int> &items);
    void ExtendFront(int items[], int size);
    void ExtendFront(std::vector<int> &items);
    void PushAt(int index, int data);

    int PopFront();
    int PopBack();
    int RemoveAt(int index);
    int Remove(int data);
    void Clear();

    bool Contains(int data);
    int Get(int index);
    int& Set(int index);
    int IndexOf(int data);

    int& operator[](int index);

private:
    Node *m_HeadNode = nullptr;
    Node* ReverseRecursive(Node* head);
};