#!/bin/env python3

def recursiveNum(arr):
    size = len(arr)
    if 0 == size:
        return None
    elif 1 == size:
        return 1
    else:
        return 1+recursiveNum(arr[1:size])

if __name__ == "__main__":
    arrList = [1,5,2,3,4,3,4,5]
    print("%s's size :%s" % (arrList, recursiveNum(arrList)))