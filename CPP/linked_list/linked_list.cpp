#include "linked_list.h"
#include "iostream"
#include "stdexcept"

Node::Node(int data, Node *next)
    : data(data), next(next) {}

LinkedList::LinkedList(int items[], int size)
{
    this->ExtendFront(items, size);
}

LinkedList::LinkedList(std::vector<int> &items)
{
    this->ExtendFront(items);
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
    while (tmp->next != nullptr)
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

/**
 * @brief Appends an array of int to the back of the list
 *
 * @param items vector<int> of items
 */
void LinkedList::ExtendBack(std::vector<int> &items)
{
    if (m_HeadNode == nullptr)
    {
        m_HeadNode = new Node(items[0], nullptr);
        items.erase(items.begin());
    }
    auto tmp = m_HeadNode;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    for (auto &item : items)
    {
        tmp->next = new Node(item, nullptr);
        tmp = tmp->next;
    }
}

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
    auto head = m_HeadNode;
    m_HeadNode = tmp;
    for (int i = 1; i < size; i++)
    {
        tmp->next = new Node(items[i], nullptr);
        tmp = tmp->next;
    }
    tmp->next = head;
}

/**
 * @brief Appends an array of int to the front of the list
 *
 * @param items vector<int> of items
 */
void LinkedList::ExtendFront(std::vector<int> &items)
{
    auto tmp = new Node(items[0], nullptr);
    auto head = m_HeadNode;
    m_HeadNode = tmp;
    items.erase(items.begin());
    for (auto &item : items)
    {
        tmp->next = new Node(item, nullptr);
        tmp = tmp->next;
    }
    tmp->next = head;
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

int LinkedList::PopFront()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto tmp = m_HeadNode;
    auto data = tmp->data;
    m_HeadNode = m_HeadNode->next;
    delete tmp;
    return data;
}

int LinkedList::PopBack()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto tmp = m_HeadNode;

    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    auto tail = tmp->next;
    auto data = tmp->next->data;
    delete tail;
    tmp->next = nullptr;
    return data;
}

int LinkedList::RemoveAt(int index)
{
    int size = this->size();

    THROW_IF_EMPTY_LIST(m_HeadNode);

    // CASE: Remove first item of the list
    if (index == 0)
    {
        return this->PopFront();
    }

    // CASE: Remove the last item
    if (index == size - 1)
    {
        return this->PopBack();
    }

    int count = 0;

    

}

int main()
{
    std::vector<int> items({1,2,3,4,5});
    LinkedList ll(items);
    ll.print();
    ll.PopFront();
    ll.print();
    ll.PopBack();
    ll.print();
}