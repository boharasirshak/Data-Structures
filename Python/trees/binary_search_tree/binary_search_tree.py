from __future__ import annotations
from dataclasses import dataclass
from typing import Any


@dataclass
class Node:
    data: Any
    left: Node = None
    right: Node = None


class BinarySearchTree:
    def __init__(self) -> None:
        self._root = Node(0)

    def search(self, item: Any) -> bool:
        pass

    def insert(self, item: Any) -> bool:
        pass

    def delete(self, item: Any) -> Any:
        pass
