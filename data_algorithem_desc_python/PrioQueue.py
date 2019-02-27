#!/bin/env python3

class PrioQueueError(ValueError):
    pass

class PrioQueue:
    """ Implement priorty queue by heap.
    """ 

    def __init__(self, elist=[]):
        self._elems = list(elist)
        if elist:
            self.build_heap()

    def is_empty(self):
        return not self._elems

    def peek(self):
        if self.is_empty():
            raise PrioQueueError("in peek")
        return self._elems[0]

    def enqueue(self, e):
        self._elems.append(None)
        self.sift_up(e, len(self._elems)-1)

    def sift_up(self, e, last):
        elems, i, j = self._elems, last, (last-1)//2
        while i>0 and e<elems[j]:
            elems[i] = elems[j]
            i, j = j, (j-1)//2
        elems[i] = e

    def dequeue(self):
        if self.is_empty():
            raise PrioQueueError("in dequeue.")
        elems = self._elems
        e0 = elems[0]
        e = elems.pop()

        if len(elems)>0:
            self.sift_down(e, 0, len(elems))
        return e0

    def sift_down(self, e, begin, end):
        elems, i, j = self._elems, begin, begin*2+1     #左子树

        while j < end:
            if j+1 < end and elems[j+1] < elems[j]:         # j 指向最小子树下标
                j+=1
            if e < elems[j]:
                break;
            elems[i] = elems[j]
            i, j = j, j*2 +1
        elems[i] = e

    def build_heap(self):
        end = len(self._elems)
        for i in range(end//2, -1, -1):
            print(self._elems)
            print(self._elems[i], i, end)
            self.sift_down(self._elems[i],i ,end )
            print(self._elems)


if __name__ == "__main__":
    l = [10,2,43,4,3,65,4]
    q = PrioQueue(l)
    print(q._elems)
    while not q.is_empty():
        print(q.dequeue())

    
    
