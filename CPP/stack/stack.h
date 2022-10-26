#ifndef STACK_H_
#define STACK_H_
#endif

#include "vector"

/**
 * @brief A templated Stack implementation using std::vector
 */

template <class T>
class Stack
{
public:
    Stack();
    Stack(std::vector<T> items);
    ~Stack();

    bool IsEmpty();
    void Push(T item);
    T Pop();
    T& Top();

private:
    std::vector<T> m_Stack; 
    int m_Index = -1; // -1 represents empty
};