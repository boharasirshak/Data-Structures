from dataclasses import dataclass
from typing import Any, List

@dataclass
class Node:
    data: Any
    next: Any

class LinkedList:
    def __init__(self) -> None:
        self._head = None

    @property
    def size(self):
        if self._head is None:
            return 0

        tmp = self._head
        count = 0
        while tmp:
            count += 1
            tmp = tmp.next
        
        return count
        
    def print(self):
        if self._head is None:
            print('[]')
            return 

        tmp = self._head
        datas = []
        while tmp:
            datas.append(tmp.data)
            tmp = tmp.next
        
        print(datas)

    def push_front(self, data: Any):
        self._head = Node(data, self._head)
    
    def push_back(self, data: Any):
        if self._head is None:
            self._head = Node(data, None)
            return
        
        tmp = self._head
        while tmp.next:
            tmp = tmp.next            
        
        tmp.next = Node(data, None)
    
    def extend_back(self, datas: List[Any]):
        tmp = self._head
        while tmp.next:
            tmp = tmp.next
        
        for data in datas:
            tmp.next = Node(data, None)
            tmp = tmp.next    
    
    def extend_front(self, datas: List[Any]):
        tmp = self._head
        for data in reversed(datas):
            tmp = Node(data=data, next=tmp)
        
        self._head = tmp
    
    def push_at(self, data: Any, index: int):
        size = self.size - 1 
        if index > size:
            raise IndexError("Index more than the size of list!")

        # if negative index is passed it will count from backwards
        # similar to default lists in python
        if index < 0:
            index = size - index
        
        count = 0
        tmp = self._head
        
        while count < index - 1:
            tmp = tmp.next
            count += 1
        
        tmp.next = Node(data, tmp.next)

    def pop_at(self, index: int):
        size = self.size - 1 
        if index > size:
            raise IndexError("Index more than the size of list!")

        # if negative index is passed it will count from backwards
        # similar to default lists in python
        if index < 0:
            index = size - index
        
        tmp = self._head
        count = 0
        
        while count < index - 1:
            tmp = tmp.next
            count += 1
        
        var = tmp.next.next
        del tmp.next
        tmp.next = var
    
    def pop(self, data: Any):
        tmp = self._head
        
        while tmp.next:
            if tmp.next.data == data:
                var = tmp.next.next
                del tmp.next
                tmp.next = var
                
            tmp = tmp.next
    
if __name__ == '__main__':
    ll = LinkedList()
    ll.extend_front([0,1,2,3,4,5])
    ll.extend_back([6,7,8,9,10])
    ll.print()
    ll.pop_at(2)
    ll.print()
    ll.pop(8)
    ll.print()