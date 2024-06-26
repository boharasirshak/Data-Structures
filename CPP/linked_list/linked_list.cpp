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

LinkedList::~LinkedList()
{
    if (m_HeadNode != nullptr)
        this->Clear();
}

int LinkedList::size()
{
    auto head = m_HeadNode;
    int count = 0;
    while (head)
    {
        head = head->next;
        ++count;
    }
    return count;
}

void LinkedList::Print()
{
    auto head = m_HeadNode;
    std::cout << "[ ";
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Reverses the link list using iterative method
 */
void LinkedList::Reverse()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);

    auto current = m_HeadNode;
    Node *prev = nullptr, *next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    m_HeadNode = prev;
}

/**
 * @brief Actual  implementation of the recusrive linked list reversing
 *
 * @param head The head node
 * @return Node* The reversed head node
 */
Node *LinkedList::ReverseRecursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    auto node = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

/**
 * @brief Reverses the linkedlist using recursion
 *
 */
void LinkedList::ReverseR()
{
    m_HeadNode = this->ReverseRecursive(m_HeadNode);
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

    auto head = m_HeadNode;
    while (head->next != nullptr)
        head = head->next;

    head->next = new Node(data, nullptr);
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
    auto head = m_HeadNode;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    for (auto &item : items)
    {
        head->next = new Node(item, nullptr);
        head = head->next;
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

    auto head = m_HeadNode;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    for (; i < size; i++)
    {
        head->next = new Node(items[i], nullptr);
        head = head->next;
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

/**
 * @brief Pushes a new entry to the specifed index
 *
 * @param index The index of the list to push at
 * @param data The data to push
 *
 * @throw std::out_of_range When the index is more than the size of the list
 */
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

    auto head = m_HeadNode;
    int count = 0;

    while (count < index - 1)
    {
        head = head->next;
        count++;
    }
    head->next = new Node(data, head->next);
}

/**
 * @brief Removes and returns the first entry of the list
 *
 * @return int The first entry that was removed
 */
int LinkedList::PopFront()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto head = m_HeadNode;
    auto data = head->data;
    m_HeadNode = m_HeadNode->next;
    delete head;
    return data;
}

/**
 * @brief Removes and retuns the last entry of the list
 *
 * @return int The last entry of the list which was removed
 */
int LinkedList::PopBack()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto head = m_HeadNode;

    while (head->next->next)
    {
        head = head->next;
    }
    auto tail = head->next;
    auto data = head->next->data;
    delete tail;
    head->next = nullptr;
    return data;
}

/**
 * @brief Removes the entry at the specified index in the list
 *
 * @param index The index which have to be removed
 * @return int The removd entry
 */
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

    auto head = m_HeadNode;
    int count = 0;

    while (count < index - 1)
    {
        head = head->next;
        count++;
    }
    auto entry = head->next;
    auto data = entry->data;
    head->next = head->next->next;
    delete entry;
    return data;
}

/**
 * @brief Removes the first item that matches the data
 *
 * @param data The data to remove from the list
 * @return int The index of the rmeoved data+
 *
 * @throw std::invaid_argument When the list is empty
 * @throw std::invaid_argument When the item is not present in the list
 */
int LinkedList::Remove(int data)
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto head = m_HeadNode;
    int index = 0;

    // CASE: delete first item
    if (head->data == data)
    {
        this->PopFront();
        return index;
    }

    while (head->next)
    {
        if (head->next->data == data)
        {
            auto entry = head->next;
            head->next = head->next->next;
            delete entry;
            return index;
        }
        head = head->next;
        index++;
    }
    throw std::invalid_argument("Data not found in the list");
}

/**
 * @brief Clears the link list
 */
void LinkedList::Clear()
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    auto head = m_HeadNode;
    m_HeadNode = nullptr;

    while (head != nullptr)
    {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
}

/**
 * @brief Checks the data contains in the list
 *
 * @param data The data to check exists
 * @return true If the data exists in the list, false otherwise
 */
bool LinkedList::Contains(int data)
{
    if (m_HeadNode == nullptr)
    {
        return false;
    }

    auto head = m_HeadNode;
    while (head)
    {
        if (head->data == data)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

/**
 * @brief Gets the item at the index position
 *
 * @param index The index
 * @return @b int The data present at the index
 */
int LinkedList::Get(int index)
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    int size = this->size();

    if (index == 0)
    {
        return m_HeadNode->data;
    }

    if (index >= size)
    {
        throw std::out_of_range("Index more than the size of the list");
    }

    auto head = m_HeadNode;
    int count = 0;

    while (count < index)
    {
        head = head->next;
        count++;
    }
    return head->data;
}

// This function is a direct copy-paste of the Get() function
// Need to find a better way to return the int&
/**
 * @brief Just like the Get() function, but we can assaign the value at the given index
 *
 * @param index The index to get/set data
 * @return int& The reference to the data at the position
 *
 */
int &LinkedList::Set(int index)
{
    THROW_IF_EMPTY_LIST(m_HeadNode);
    int size = this->size();

    if (index == 0)
    {
        return m_HeadNode->data;
    }

    if (index >= size)
    {
        throw std::out_of_range("Index more than the size of the list");
    }

    auto head = m_HeadNode;
    int count = 0;

    while (count < index)
    {
        head = head->next;
        count++;
    }
    return head->data;
}

/**
 * @brief Gets the index of the first entry that matches the `data`
 *
 * @param data The data to get the index
 * @return int - If data is present in the list, returns its index, otherwise will returns -1
 */
int LinkedList::IndexOf(int data)
{
    THROW_IF_EMPTY_LIST(m_HeadNode);

    int count = 0;
    auto head = m_HeadNode;

    while (head)
    {
        if (head->data == data)
        {
            return count;
        }
        head = head->next;
        count++;
    }

    return -1;
}

int &LinkedList::operator[](int index)
{
    return this->Set(index);
}

int main()
{
}
