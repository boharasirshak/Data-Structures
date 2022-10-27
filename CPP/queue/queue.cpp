#include "iostream"
#include "queue.h"
#include "stdexcept"

template <class T>
Queue<T>::Queue()
{
    this->init();
}

template <class T>
Queue<T>::Queue(int max) : m_Max(max) 
{
    this->init();
}

template <class T>
void Queue<T>::init()
{
    p_Queue = new T[m_Max];
    for (int i = 0; i < m_Max; i++)
    {
        *(p_Queue + i) = 0; // 0 = NULL
    }
}

template <class T>
Queue<T>::~Queue()
{
    delete[] p_Queue;
}

template <class T>
bool Queue<T>::isFull()
{
    return this->back() + 1 == m_Max;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return this->front() == this->back();
}

template <class T>
T& Queue<T>::first()
{
    if (this->isEmpty())
    {
        throw std::invalid_argument("Empty Queue");
    }
    return *(this->p_Queue + this->front()); 
}

template <class T>
void Queue<T>::enqueue(T data)
{
    if (this->isFull())
    {
        throw std::out_of_range("Queue overflow");
    }
    *(this->p_Queue + this->back()) = data;
    this->m_Back++;
}

template <class T>
T Queue<T>::dequeue()
{
    // If the front and back index are equal
    // This means the queue is now empty, 
    // we can set the front and back to -1
    if (m_Front == m_Back)
    {
        m_Front = m_Back = -1;
    }
    if(this->isEmpty())
    {
        throw std::invalid_argument("Empty Queue");
    }
    T data = *(this->p_Queue + this->front());
    this->m_Front++; 
    return data;
}

template <class T>
int Queue<T>::front()
{
    return (this->m_Front + 1) % this->m_Max;
}

template <class T>
int Queue<T>::back()
{
    return (this->m_Back + 1) % this->m_Max;
}

int main()
{
    Queue<int> q;
}