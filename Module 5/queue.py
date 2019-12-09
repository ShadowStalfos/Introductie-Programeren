# Implements a queue
class Queue:
    
    def __init__(self):
        self._data = []
        
    def enqueue(self, element):
        self._data.append(element)
    
    def dequeue(self):
        assert self.size > 0
        return self._data.pop(0)
    
    def size(self):
        return len(self._data)
    
    def peek(self):
        return self._data[0]
    
    def empty(self):
        self._data = []
