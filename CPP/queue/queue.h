#ifndef QUEUE_H_
#define QUEUE_H_
#endif

template <class T>
class Queue
{
public:
    Queue();
    Queue(int max);
    ~Queue();

    bool isFull();
    bool isEmpty();
    T& first();
    void enqueue(T data);
    T dequeue();

private:
    int m_Max = 100;
    T *p_Queue; // the actual queue
    int m_Front = -1;
    int m_Back = -1;

    void init();
    int front();
    int back();
};