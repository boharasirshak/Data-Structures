from dataclasses import dataclass
from typing import Any, List

@dataclass
class Node:
    data: Any
    next: Any

class LinkedList:
    def __init__(self, items: List[Any] = None) -> None:
        self._head = None
        
        if items:
            self.extend_back(items)
        
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
        if not self._head:
            self._head = Node(datas[0], None)
            datas.pop(0)
            tmp = self._head
            for data in datas:
                tmp.next = Node(data, None)
                tmp = tmp.next   
            
            return 
        
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
    
    def push_at(self, index: int, data: Any) -> None:
        """Pushes a new element to the given `index`

        Args:
            index (int): The index to push
            data (Any): The element to push

        Raises:
            IndexError: When the given index is more than the size of the list
        """
        size = self.size
        
        # CASE: index is -ve, count from reverse order
        if index < 0:
            index = size + index + 1

        # CASE: Empty list or push at first
        if size == 0 or index == 0:
            self.push_front(data)
            return

        count = 0
        tmp = self._head
        
        # CASE: push at the last of the list
        if index == size:
            self.push_back(data)
            return
        
        # CASE: index is more than the size of the list
        if index > size:
            raise IndexError("Index more than the size of list!")

        
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
        # delete at first
        if index == 0:
            tmp = self._head
            self._head = self._head.next
            return tmp.data

        size = self.size

        if index < 0:
            index = size + index
        
        if index > size - 1:
            raise IndexError("Index more than the size of list!")
            
        tmp = self._head
        count = 1
        
        while count < index:
            tmp = tmp.next
            count += 1
        
        data = tmp.next.data
        tmp.next = tmp.next.next
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
        
        # CASE: Deletion at first element
        if tmp.data == data:
            tmp.next = tmp.next.next
            return count
        
        while tmp.next:
            if tmp.next.data == data:
                tmp.next = tmp.next.next
                return count + 1
                
            tmp = tmp.next
            count += 1
        
        raise ValueError("The data is not fount in the list")

    # TODO: not implemented
    def replace_at(self, index: int, item: Any) -> None:
        raise NotImplemented

    # TODO: not implemented
    def replace(self, data: Any) -> None:
        raise NotImplemented
    
    def clear(self) -> None:
        """Clears all the elementss contained by the list
        """
        self._head = None
    
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
        """Gets the element at the specified index

        Args:
            index (int): The index

        Raises:
            IndexError: When index is more than the size of the list

        Returns:
            Any: The data at the given index
        """
        size = self.size
        if index >= size:
            raise IndexError("Index more than the size of list!")

        if index < 0:
            index = size + index
        
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
        self.replace_at(key, item)

    def __contains__(self, data: Any) -> bool:
        return self.contains(data)
    
    def __repr__(self) -> str:
        return f"LinkedList({str(self.to_list())})"
    
    def __str__(self) -> str:
        return str(self.to_list())
    
    def __iter__(self):
        self._index = -1
        self._max = self.size 
        return self

    def __next__(self):        
        self._index += 1
        
        if self._index >= self._max:
            raise StopIteration
        
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
    ll = LinkedList([1,2,3,4])
    