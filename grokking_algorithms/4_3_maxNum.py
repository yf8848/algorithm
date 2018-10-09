#!/bin/env python3

def recursiveNum(arr):
    size = len(arr)
    if 0 == size:
        return None
    elif 1 == size:
        return arr[0]
    else:
        temp = recursiveNum(arr[1:size])
        if temp > arr[0]:
            return temp
        else:
            return arr[0]

if __name__ == "__main__":
    arrList = [5,2,3,4,3,4,5]
    print("%s's max num :%s" % (arrList, recursiveNum(arrList)))