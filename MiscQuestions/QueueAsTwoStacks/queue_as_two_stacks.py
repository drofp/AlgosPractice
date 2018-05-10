''' 
Further improvments can be made by looking up:
- alternate/better ways to format __repr__ and __str__
- build test suite
'''

class QueueAsTwoStacks(object):
    
    def __init__(self):
        self.in_stack = []
        self.out_stack = []
        
    def enqueue(self, item):
        self.in_stack.append(item)
    
    def dequeue(self):
        if len(self.out_stack) == 0:
            
            # Push all from in_stack to out_stack in reverse order
            for _ in range(len(self.in_stack)):
                self.out_stack.append(self.in_stack.pop())
            # If out_stack is still empty, raise error
            if len(self.out_stack) == 0:
                raise IndexError("Queue is empty. Cannot dequeue")
                
        return self.out_stack.pop()
    
    # Python 3
    # def __repr__(self):
    #     return f'Queue({self.in_stack}, {self.out_stack})'
    
    def __repr__(self):
        return "Queue(" + str(self.in_stack) + ", " + str(self.out_stack) + ")"
    
    def __str__(self):
        return "in_stack: " + str(self.in_stack) + ", out_stack: " + str(self.out_stack)

if __name__ == "__main__":
    q = QueueAsTwoStacks()
    
    print "Test enqueueing (4 test input)"
    q.enqueue(5)
    q.enqueue(6)
    q.enqueue(7)
    q.enqueue(8)
    print q
    print ""
    
    print "Test initial dequeueing (2x)"
    q.dequeue()
    q.dequeue()
    print q
    print ""
    
    print "Test enqueue after initial dequeueing (1 enqueue, 1 dequeue)"
    q.enqueue(42)
    print q
    q.dequeue()
    print q
    print ""
    
    print "Test moving in_stack to out_stack again when needed (1 enqueue, 2 dequeue)"
    q.enqueue(24)
    print q
    q.dequeue()
    q.dequeue()
    print q
    print ""