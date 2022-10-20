from dataclasses import dataclass
from typing import Any, List

@dataclass
class Node:
    data: Any
    next: Any

class LinkedList:
    def __init__(self) -> None:
        self._head = None
        
        # variables for __iter__ methods
        self._index = 0
        self._max = 0

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
    
    @property
    def to_list(self) -> list:
        if self._head is None:
            return []

        tmp = self._head
        items = []
        while tmp:
            items.append(tmp.data)
            tmp = tmp.next
        
        return items
            
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

        if index < 0:
            index = size - index
        
        count = 0
        tmp = self._head
        
        while count < index - 1:
            tmp = tmp.next
            count += 1
        
        tmp.next = Node(data, tmp.next)

    def remove_at(self, index: int) -> Any:
        """Removes a item at the specified 

        Args:
            index (int): The index whose element is to be removed

        Raises:
            IndexError: When the given index is more than that of the size of the list

        Returns:
            Any: The data at the `index` that was deleted
        """
        size = self.size - 1 
        if index > size:
            raise IndexError("Index more than the size of list!")

        if index < 0:
            index = size - index
        
        tmp = self._head
        count = 0
        
        while count < index - 1:
            tmp = tmp.next
            count += 1
        
        var = tmp.next.next
        data = tmp.next.data
        del tmp.next
        tmp.next = var
        return data
    
    def remove(self, data: Any) -> int:
        """Removed a element which matches with the data 

        Args:
            data (Any): The data to match

        Returns:
            Any: Returns the index of the removed data
        
        Raises:
            ValueError: When the data not found in the list
        """
        tmp = self._head
        count = 0
        
        while tmp.next:
            if tmp.next.data == data:
                var = tmp.next.next
                del tmp.next
                tmp.next = var
                return count
                
            tmp = tmp.next
            count += 1
        
        raise ValueError("The data is not fount in the list")

    def contains(self, data: Any) -> bool:
        """Checks if  item contains with the specified `data` in the list

        Args:
            data (Any): The data to check

        Returns:
            bool: True if the data exists in the list, False otherwise
        """
        tmp = self._head
        while tmp:
            if tmp.data == data:
                return True
            tmp = tmp.next

        return False
    
    def get(self, index: int) -> Any:
        size = self.size
        if index > size:
            raise IndexError("Index more than the size of list!")

        if index < 0:
            index = size - index
        
        tmp = self._head
        count = 0
        
        while count < index:
            tmp = tmp.next
            count += 1
        
        return tmp.data
        
    def index_of(self, data: Any) -> int:
        """Returns the index of the `data` in the list

        Args:
            data (Any): The data to search

        Returns:
            int: Returns a positive index value if successful
                 -1 if the data is not in the list
        """
        tmp = self._head
        count = 0
        
        while tmp:
            if tmp.data == data:
                return count
            tmp = tmp.next
            count += 1
        
        return -1
    
    def __getitem__(self, index: int) -> Node:
        return self.get(index)

    def __setitem__(self, key: int, item: Any):
        if not isinstance(key, int):
            raise ValueError("The index type should only be a integer")
        self.push_at(key, item)

    def __contains__(self, data: Any) -> bool:
        return self.contains(data)
    
    def __repr__(self) -> str:
        return f"LinkedList({str(self.to_list)}"
    
    def __str__(self) -> str:
        return str(self.to_list)
    
    def __iter__(self):
        self._index = 0
        self._max = self.size 
        return self

    def __next__(self):
        if self._index > self._max:
            raise StopIteration
        
        self._index += 1
        return self.get(self._index)
    
    # TODO: Not implemented
    def __reversed__(self):
        raise NotImplemented()
    
    def __len__(self) -> int:
        return self.size

    def __delitem__(self, index: int):
        if not isinstance(index, int):
            raise ValueError("The index type should only be a integer")
        self.remove_at(index)
    
    
if __name__ == '__main__':
    ll = LinkedList()
    ll.extend_front([0,1,2,3,4,5])
    ll.extend_back([6,7,8,9,10])
    ll.print()
    ll.pop_at(2)
    ll.print()
    ll.pop(8)
    ll.print()