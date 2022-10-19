#include "LinkedList.h"
#include "iostream"

Node::Node() : data(0), next(nullptr) {}

Node::Node(Node *next) : data(0), next(next)  {}

Node::Node(int data, Node* next) : data(data), next(next) {}

LinkedList::LinkedList()
{
	p_headNode = nullptr;
}

LinkedList::~LinkedList() = default;

Node* LinkedList::getHeadNode() {
  return p_headNode;
}

int LinkedList::Add(int data) {
	auto tmp = new Node(data, p_headNode);
	p_headNode = tmp;
	return ++m_index;
}
