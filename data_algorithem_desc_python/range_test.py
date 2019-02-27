#!/bin/env python3

l = [1,2,3,4,5,6,7]
end = len(l)
print("end: %d." % end)
for i in range(end//2, -1, -1):
    print(i, l[i])
