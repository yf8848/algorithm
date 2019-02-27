#!/bin/env python

class Solution:
    def replaceSpace(self, s):
        print list(s)
        strList = s.split(' ')
        print strList
        s = "%20".join(strList)
        print s
        

if __name__=="__main__":
    a =  Solution()
    a.replaceSpace(" how are   you")
