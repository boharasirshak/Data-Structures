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

int LinkedList::GetIndexOf(int data)
{
    int index = 0;
    Node* tmp = m_headNode;
    while (tmp != nullptr)
    {
        if (tmp->data == data)
        {
            return index;
        }
        tmp = tmp->next;
        index++;
    }
    return -1;
}

bool LinkedList::DeleteAt(int position)
{
    Node* tmpNode = m_headNode;
    int index;

    if (position == 1)
    {
        m_headNode = tmpNode->next;
        delete tmpNode;
        return true;
    }

    if ((index - 2) == 0)
    {
        return false;
    }

    for (int i = 0; i < index - 2; i++)
    {
        tmpNode = tmpNode->next;
    }

    Node* prevNode = tmpNode->next;
    tmpNode->next = prevNode->next;
    delete tmpNode; 
    return true;
}

bool LinkedList::Delete(int data)
{
    int index = GetIndexOf(data);
    if (index == -1)
    {
        return false;
    }
    return DeleteAt(index);
}