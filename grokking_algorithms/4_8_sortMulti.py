#!/bin/env python3

def multiList(a, arr):
    for i in range(len(arr)):
        arr[i]*=a

def sortMulti(arr):
    size = len(arr)
    if 0 == size:
        return None
    elif 1 == size:
        return [arr[0]*arr[0]]
    else:
        list = [arr[0]*i for i in arr[1:]]
        return [arr[0]*arr[0]] + sortMulti(list)

if __name__ == "__main__":
    arr = [2,3,4]
    print("%s's sorted miltiplate result: %s." % (arr, sortMulti(arr)))