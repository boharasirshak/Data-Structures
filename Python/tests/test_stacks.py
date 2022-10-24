import pytest
from stack import Stack

def test_properties():
    stack = Stack()    
    assert stack.is_empty is True
    assert stack.top is None
    
def test_push():
    stack = Stack()
    stack.push(1)
    assert stack.top == 1
    
    stack = Stack([1,2,3,4])
    assert stack.top == 4
    
    
def test_pop():
    stack = Stack()
    with pytest.raises(IndexError) as e:
        stack.pop()
    assert str(e.value) == "Empty stack"
    
    stack.push(1)
    assert stack.pop() == 1
    with pytest.raises(IndexError) as e:
        stack.pop()
    assert str(e.value) == "Empty stack"