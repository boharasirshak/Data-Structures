import pytest
from linked_lists import LinkedList

def test_conversion():
    ll_1 = LinkedList()
    ll_2 = LinkedList([1,2])
    assert ll_1.to_list() == []
    assert ll_2.to_list() == [1,2]
        
def test_insertion():
    ll = LinkedList()
    ll.push_back(1)
    assert ll.to_list() == [1]
    ll.extend_back([2,3])
    assert ll.to_list() == [1,2,3]
    
    ll = LinkedList()
    ll.push_front(3)
    assert ll.to_list() == [3]
    ll.extend_front([1,2])
    assert ll.to_list() == [1,2,3]
    
    ll = LinkedList()
    ll.push_at(0, 0)
    assert ll.to_list() == [0]
    ll.push_at(1, 1)
    assert ll.to_list() == [0, 1]
    ll.push_at(-1, 2)
    assert ll.to_list() == [0,1,2]
    ll.push_at(1, 0.5)
    assert ll.to_list() == [0, 0.5, 1, 2]

def test_deletion():
    ll = LinkedList([0,0,1,2,2,3,4,5,6])
    assert ll.remove_at(0) == 0 # delete at first
    assert ll.remove_at(-1) == 6 # delete at last
    assert ll.remove_at(-2) == 4 # delete at last
    assert ll.remove_at(2) == 2 # delete at middle
    
    assert ll.remove(0) == 0 # delete first
    assert ll.remove(3) == 2 # delete middle
    assert ll.remove(5) == 2 # delete last
    
    ll.clear()
    assert ll.size == 0

def test_search():
    ll = LinkedList([0,1,2,3,4,5,6,7,8,9])

    assert ll.get(0) == 0 # at first
    assert ll.get(4) == 4 # at middle
    assert ll.get(9) == 9 # at last
    assert ll.get(-1) == 9 # negative index
    assert ll.get(-2) == 8 # negative index
    
    assert ll.index_of(0) == 0 # at first
    assert ll.index_of(9) == 9 # at last
    assert ll.index_of(4) == 4 # at middle
    assert ll.index_of(-1) == -1 # not present
    
    assert ll[0] == 0 # at first
    assert ll[4] == 4 # at middle
    assert ll[9] == 9 # at last
    assert ll[-1] == 9 # negative index
    assert ll[-2] == 8 # negative index
    
def test_special_functions():
    l = [1,2,3]
    ll = LinkedList(l)
    
    assert str(ll) == '[1, 2, 3]'               # __str__ test
    assert repr(ll) == 'LinkedList([1, 2, 3])'  # __repr__ test
   
    # __iter__ test
    for item in ll:
        print(item)
    
    # __contains__ test    
    assert 1 in ll
   