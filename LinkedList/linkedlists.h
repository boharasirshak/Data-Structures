#pragma once

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    void Append(int data);
    void Insert(int data);
    void InsertAt(int data, int position);
    void PrintList();

private:
    Node* m_headNode = nullptr;

};