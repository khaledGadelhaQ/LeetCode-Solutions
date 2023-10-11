class node:
    def __init__(self,val = 0 ,next =None):
        self.val = val
        self.next = None

class MyCircularQueue:

    def __init__(self, k: int):
        self.size = k
        self.length = 0 
        self.head = None
        self.tail = None
    

    def enQueue(self, value: int) -> bool:
        if self.isFull(): return False
        item = node(value)
        if not self.head:
            self.head = self.tail = item
        else:
            self.tail.next = item
            self.tail = self.tail.next
        self.tail.next = None
        self.length += 1
        return True

 
    def deQueue(self) -> bool:
        if self.isEmpty(): return False
        self.head = self.head.next
        self.length -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty(): return -1
        return self.head.val

    def Rear(self) -> int:
        if self.isEmpty(): return -1
        return self.tail.val

    def isEmpty(self) -> bool:
        return self.length == 0

    def isFull(self) -> bool:
        return self.length == self.size
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()