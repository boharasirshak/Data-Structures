#include <iostream>
#include <cstdlib>
#include <linkedlists.h>

LinkedList::LinkedList()
{
    m_headNode = nullptr;
}

void LinkedList::Insert(int data)
{
    Node* newNode = new Node(data);
    if (m_headNode != nullptr)
    {
        newNode->next = m_headNode;
    }
    m_headNode = newNode;
}

void LinkedList::InsertAt(int data, int position)
{
    Node* newNode = new Node(data);
    if (position == 1)
    {
        newNode->next = m_headNode;
        m_headNode = newNode;
        return;
    }

    Node* tmpNode = m_headNode;
    for (int i = 0; i < position - 2; i++)
    {
        tmpNode= tmpNode->next;
    }

    newNode->next = tmpNode->next;
    tmpNode->next = newNode;
}

void LinkedList::PrintList()
{
    Node* tmp = m_headNode;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}



int main()
{
    LinkedList list; 
    list.PrintList();

    return 0;
}