import sys
from io import StringIO
import unittest

doTest=0

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline
    a=[]
    b=[]
    n,m=list(map(int, readline().strip().split()))
    for _ in range(n):
        a.append(readline().strip())
    for _ in range(m):
        b.append(readline().strip())

    hikaku=""
    for one in b:
        hikaku += one

    #n*n
    #m*m
    for i in range(n-m+1):
        for j in range(n-m+1):
            tmp=""
            for k in range(m):
                tmp+=str(a[j+k])[i:i+m]
            if tmp==hikaku:
                print("Yes")
                return
    print("No")

    return

if doTest==0:
    resolve()
    sys.exit()
