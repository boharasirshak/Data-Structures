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
     * @brief Add data to the end of the list
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

    /**
     * @brief delets the node at the given position
     * 
     * @param position The position to delete
     * @return true if succcessfully deleting a node
     * @return false if no such index exists
     */
    bool DeleteAt(int position);
    
    /**
     * @brief Delets the node with data if it exists
     * 
     * @param data The data to delete
     * @return true if succcessfully deleting a node
     * @return false if no such node is found
     */
    bool Delete(int data);

    /**
     * @brief Get the Index Of the node containing data
     * 
     * @param data The data to find
     * @return int The index of the node containing data
     */
    int GetIndexOf(int data);

    /**
     * @brief Prints the list
     * 
     */
    void PrintList(void);

private:
    Node* m_headNode = nullptr;

};