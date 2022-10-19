#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

#endif //DATA_STRUCTURES_LINKEDLIST_H

struct Node {
    int data;
    Node *next;
	Node();
	Node(Node *next);
	Node(int data, Node* next);
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
	Node* getHeadNode();
	int Add(int data);

private:
    Node *p_headNode;
	int m_index;
};