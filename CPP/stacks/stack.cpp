#include "stack.h"
#include "iostream"
#include "stdexcept"

/**
 * @brief Construct a new Stack< T>:: Stack object
 * 
 * @tparam T The type of items in the stack
 */
template <class T>
Stack<T>::Stack() = default;

/**
 * @brief Construct a new Stack< T>:: Stack object
 * 
 * @tparam T The type of items in the stack
 * @param items The std::vector of the default items in the stack, 
 */
template <class T>
Stack<T>::Stack(std::vector<T> items)
{
    for (T &item : items)
    {
        this->Push(item);
    }
} 

template <class T>
Stack<T>::~Stack()
{
    m_Stack.clear();
    m_Index = -1;
} 

/**
 * @brief Checks if the stack is empty or not
 * 
 * @return true if empty, false otherwise
 */
template <class T>
bool Stack<T>::IsEmpty()
{
    return m_Index == -1;
}

/**
 * @brief Returns the top member of the stack
 * 
 * @return T The top member with read/write reference  
 * @throw std::invalid_argument When the stack is empty 
 */
template <class T>
T& Stack<T>::Top()
{
    if (this->IsEmpty())
    {
        throw std::invalid_argument("Empty stack");
    }
    return this->m_Stack[this->m_Index];
}

/**
 * @brief Pushes a new item to top of the stack
 * 
 * @param item The item to push
 */
template <class T>
void Stack<T>::Push(T item)
{
    this->m_Stack.push_back(item);
    this->m_Index++;
}

/**
 * @brief Removes and returns the top item from the stack
 * 
 * @return T The removed item
 * @throw std::invalid_argument When the stack is empty 
 */
template <class T>
T Stack<T>::Pop()
{
    if (this->IsEmpty())
    {
        throw std::invalid_argument("Empty stack");
    }
    T item = this->m_Stack[m_Index];
    this->m_Stack.pop_back();
    this->m_Index--;
    return item;
}

int main()
{
}