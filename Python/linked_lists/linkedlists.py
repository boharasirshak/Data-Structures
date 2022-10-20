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
    def size(self) -> int:
        if self._head is None:
            return 0

        tmp = self._head
        count = 0
        while tmp:
            count += 1
            tmp = tmp.next
        
        return count
        
    def print(self) -> None:
        if self._head is None:
            print('[]')
            return 

        tmp = self._head
        datas = []
        while tmp:
            datas.append(tmp.data)
            tmp = tmp.next
        
        print(datas)

    def push_front(self, data: Any) -> None:
        """Pushes a new element to the front of the list

        Args:
            data (Any): The data to push
        """
        self._head = Node(data, self._head)
    
    def push_back(self, data: Any) -> None:
        """Pushes a new element to the end of the list

        Args:
            data (Any): The data to push
        """
        if self._head is None:
            self._head = Node(data, None)
            return
        
        tmp = self._head
        while tmp.next:
            tmp = tmp.next            
        
        tmp.next = Node(data, None)
    
    def extend_back(self, datas: List[Any]) -> None:
        """Extends a `list` to the back of the linked list

        Args:
            datas (List[Any]): The python `list` to extend
        """
        tmp = self._head
        while tmp.next:
            tmp = tmp.next
        
        for data in datas:
            tmp.next = Node(data, None)
            tmp = tmp.next    
    
    def extend_front(self, datas: List[Any]) -> None:
        """Extends a `list` to the front of the linked list

        Args:
            datas (List[Any]): The python `list` to extend
        """
        tmp = self._head
        for data in reversed(datas):
            tmp = Node(data=data, next=tmp)
        
        self._head = tmp
    
    def push_at(self, data: Any, index: int) -> None:
        """Pushes a new element to the given `index`

        Args:
            data (Any): The element to push
            index (int): The index to push

        Raises:
            IndexError: When the given index is more than the size of the list
        """
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

    def pop_at(self, index: int) -> Node:
        """Removes a item at the specified 

        Args:
            index (int): The index whose element is to be removed

        Raises:
            IndexError: When the given index is more than that of the size of the list

        Returns:
            Node: The Node object that was deleted
        """
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
        elem = tmp.next
        elem.next = None
        tmp.next = var
        return elem
    
    def pop(self, data: Any) -> Node:
        """Removed a element which data matches with the `data`

        Args:
            data (Any): The data to match within the element

        Returns:
            Node: Returns Node object if successfully removed
        
        Raises:
            ValueError: When the the element with the specified data not found
        """
        tmp = self._head
        
        while tmp.next:
            if tmp.next.data == data:
                var = tmp.next.next
                elem = tmp.next
                elem.next = None
                tmp.next = var
                return elem
                
            tmp = tmp.next
        
        raise ValueError("The element with the specified data not found")

    
if __name__ == '__main__':
    ll = LinkedList()
    ll.extend_front([0,1,2,3,4,5])
    ll.extend_back([6,7,8,9,10])
    ll.print()
    ll.pop_at(2)
    ll.print()
    ll.pop(8)
    ll.print()