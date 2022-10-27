from __future__ import annotations
from dataclasses import dataclass
from typing import Any

@dataclass
class Node:
    data: Any
    left: Node = None
    right: Node = None

class BinarySearchTree():
    def __init__(self) -> None:
        self._root = Node(0)