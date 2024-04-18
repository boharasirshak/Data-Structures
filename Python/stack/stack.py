from typing import Any, List


class Stack:
    def __init__(self, items: List[Any] = []) -> None:
        self._stack: List[Any] = []
        self._index = -1  # -1 stands for empty
        for item in items:
            self.push(item)

    @property
    def is_empty(self) -> bool:
        return self._index == -1

    def top(self) -> Any:
        if self.is_empty:
            return None
        return self._stack[self._index]

    def push(self, item: Any) -> None:
        self._stack.append(item)
        self._index += 1

    def pop(self) -> Any:
        if self.is_empty:
            raise IndexError("Empty stack")

        self._index -= 1
        return self._stack.pop()


if __name__ == "__main__":
    stack = Stack()
