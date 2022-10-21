#include "linked_list.h"

#include "iostream"
#include "stdexcept"


Node::Node(int data, Node* next)
    : data(data), next(next) {}

LinkedList::LinkedList(std::vector<int> items)
{
    // for (auto &item : items)
    // {
    //     // self.   
    // }
    
}

int LinkedList::size()
{
    auto tmp = m_HeadNode;
    int count = 0;
    while (tmp)
    {
        tmp = tmp->next;
        ++count;
    }
    return count;
}

void LinkedList::print()
{
    auto tmp = m_HeadNode;
    std::cout << "[ ";
    while (tmp)
    {
        std::cout << tmp->data << " "; 
        tmp = tmp->next;    
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Pushes a new entry to the back of the list  
 * 
 * @param data The data to add
 */
void LinkedList::PushBack(int data) 
{
    if (m_HeadNode == nullptr)
    {
        m_HeadNode = new Node(data, nullptr);
        return;
    }

    auto tmp = m_HeadNode;
    while ( tmp->next != nullptr )
        tmp = tmp->next;

    tmp->next = new Node(data, nullptr);
}

/**
 * @brief Pushes a new entry to the front of the list   
 * 
 * @param data The data to push
 */
void LinkedList::PushFront(int data)
{
    if (m_HeadNode == nullptr)
    {
        m_HeadNode = new Node(data, nullptr);
        return;
    }
    m_HeadNode = new Node(data, m_HeadNode);
}

//  TODO: Make it work
// void LinkedList::ExtendBack(std::vector<int>& items)
// {
//     if (m_HeadNode == nullptr)
//     {
//         m_HeadNode = new Node(items[0], nullptr);
//         items.erase(items.begin());
//     }
//     auto tmp = m_HeadNode;
//     while (tmp->next != nullptr)
//     {
//         tmp = tmp->next;    
//     }
//     for(auto &item : items)
//     {
//         tmp->next = new Node(item, nullptr);
//         tmp = tmp->next; 
//     }
// }

/**
 * @brief Appends an array of int to the back of the list
 * 
 * @param items An array of int to push
 * @param size The size of the array
 */
void LinkedList::ExtendBack(int items[], int size)
{
    int i = 0;

    // CASE: Empty list
    if (m_HeadNode == nullptr)
    {
        // Create a new head node first with the 1st element
        m_HeadNode = new Node(items[0], nullptr);
        i = 1;
    }

    auto tmp = m_HeadNode;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;    
    }
    for (; i < size; i++)
    {
        tmp->next = new Node(items[i], nullptr);
        tmp = tmp->next;    
    }
}

/**
 * @brief Extends a array of int to the front of the list   
 * 
 * @param items The array of int
 * @param size The size of the array
 */
void LinkedList::ExtendFront(int items[], int size)
{
    auto tmp = new Node(items[0], nullptr);
    auto var = m_HeadNode;
    m_HeadNode = tmp;
    for (int i = 1; i < size; i++)
    {
        tmp->next = new Node(items[i], nullptr);
        tmp = tmp->next;
    }
    tmp->next = var;
}

void LinkedList::PushAt(int index, int data)
{
    int size = this->size();

    // CASE: Push at the end of the list creating new entry
    if (index == size)
    {
        return this->PushBack(data);
    }
    
    if (index > size - 1)
    {   
        throw std::out_of_range("Index more than the size of the list");
    }

    // CASE: Push at front of the list
    if (index == 0 || m_HeadNode == nullptr)
    {
        return this->PushFront(data);
    }

    auto tmp = m_HeadNode;
    int count = 0;

    while (count < index - 1)
    {
        tmp = tmp->next;
        count++;
    }
    tmp->next = new Node(data, tmp->next);
}

int main()
{
    LinkedList ll;
    ll.print();
    ll.PushBack(3);
    ll.PushBack(4);
    ll.PushBack(5);
    ll.print();
    ll.PushFront(2);
    ll.PushFront(1);
    ll.PushFront(0);
    ll.print();
    // std::cout << ll.size() << std::endl;
    ll.PushAt(6, 6);
    ll.print();
    ll.PushAt(6, 6);
    ll.print();

    int items[] = {7,8,9,10};
    int size = 4;

    ll.ExtendBack(items, size);
    ll.print();

    int items_2[] = {-5, -4,-3,-2,-1};

    ll.ExtendFront(items_2, 5);
    ll.print();
}