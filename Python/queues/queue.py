from typing import List, Any

class Queue:
    def __init__(self, n: int = 100) -> None:
        self._n = n # No of items
        self._queue = [
            None for _ in range(self._n)
        ]
        self.__front = -1
        self.__back = -1
    
    @property
    def _front(self) -> int:
        return (self.__front + 1) % self._n

    @property
    def _back(self) -> int:
        return (self.__back + 1) % self._n
    
    @property
    def is_full(self) -> bool:
        # since self.__back starts with -1
        return self.__back + 1 == self._n
    
    @property
    def is_empty(self) -> bool:
        return self._back == self._front
    
    def front(self) -> Any:
        if self.is_empty:
            raise Exception("Empty queue")
        
        return self._queue[self._front]
                  
    def enqueue(self, data: Any) -> None:
        if self.is_full:
            raise Exception("Queue overflow")
        
        self._queue[self._back] = data 
        self.__back += 1
    
    def dequeue(self) -> Any:
        # no more entries to dequeue
        if self._front == self._back:
            self.__front = -1
            self.__back = -1
        
        if self.is_empty:
            raise Exception("Empty queue")
        
        val = self._queue[self._front]
        self.__front += 1
        return val
    
if __name__ == '__main__':
    q = Queue()