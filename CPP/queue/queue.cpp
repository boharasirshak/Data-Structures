#include "queue.h"
#include "cstdlib"

template <class T>
Queue<T>::Queue()
{
    m_Queue = (T*) malloc(sizeof(T) * m_Max);
}

template <class T>
Queue<T>::Queue(int max) : m_Max(max) 
{
    m_Queue = (T*) malloc(sizeof(T) * m_Max);
}

template <class T>
Queue<T>::~Queue()
{
    delete[] m_Queue;
}

template <class T>
T Queue<T>::front()
{
    
}

template <class T>
void Queue<T>::enqueue(T data)
{
    
}

template <class T>
T Queue<T>::dequeue()
{
    
}

template <class T>
bool Queue<T>::isFull()
{
    
}

template <class T>
bool Queue<T>::isEmpty()
{
    
}


int main()
{
    Queue<int> q;
}