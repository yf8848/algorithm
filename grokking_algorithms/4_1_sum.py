#!/bin/env python3

def recursive(arr):
    size = len(arr)
    if 0 == size:
        return 0
    elif 1 == size:
        return arr[0]
    else:
        return arr[0]+recursive(arr[1:size])

if __name__ == "__main__":
    arrList = [1,2,3,4]
    print("%s's sum :%s" % (arrList, recursive(arrList)))