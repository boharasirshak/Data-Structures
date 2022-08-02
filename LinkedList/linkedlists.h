#pragma once

/**
 * @brief Structure of a Node.
 * 
 */
struct Node
{
    int data;
    Node* next;

    /**
     * @brief Construct a new Node object with next default to nullptr
     * 
     * @param value 
     */
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

public:
    /**
     * @brief Add data to the end of the list.
     * 
     * @param data The data to add.
     */
    void Append(int data);

    /**
     * @brief Add data to the beginning of the list
     * 
     * @param data The data to add
     */
    void Insert(int data);

    /**
     * @brief Add data to the given position
     * 
     * @param data The data to add
     * @param position The position to add data into list
     */
    void InsertAt(int data, int position);

    bool DeleteAt(int position);
    bool Delete(int data);

    int GetIndexOf(int data);

    /**
     * @brief Prints the list
     * 
     */
    void PrintList(void);

private:
    Node* m_headNode = nullptr;

};