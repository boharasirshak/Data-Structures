# This is named queues, to remove ambuigity 
# between standard queue, and custom queue

import pytest
from queues import Queue

def test_properties():
    q = Queue()
    assert q.is_empty == True
    assert q.is_full == False
    
    with pytest.raises(Exception) as e:
        q.front()
    assert str(e.value) == "Empty queue"
    

def test_enqueue():
    q = Queue()
    q.enqueue(0)
    assert q.is_empty == False
    assert q.front() == 0
    
    # this should not overflow the queue
    for i in range(99):
        q.enqueue(i)
    
    assert q.is_full == True
    
    with pytest.raises(Exception) as e:
        q.enqueue(100)
    assert str(e.value) == "Queue overflow"
    

def test_dequeue():
    q = Queue()
    with pytest.raises(Exception) as e:
        q.dequeue()
    assert str(e.value) == "Empty queue"
    
    q.enqueue(0)
    assert q.dequeue() == 0
    assert q.is_empty == True
    
    with pytest.raises(Exception) as e:
        q.dequeue()
    assert str(e.value) == "Empty queue"