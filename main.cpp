#include "iostream"
#include "LinkedList/LinkedList.h"

void Print(LinkedList& list)
{
  auto tmp = list.getHeadNode();
  while (tmp != nullptr) {
	std::cout << tmp->data << " ";
	tmp = tmp->next;
  }
  std::cout << std::endl;
}

int main() {
  LinkedList list;
  list.Add(10);
  list.Add(20);
  list.Add(30);
  Print(list);
}