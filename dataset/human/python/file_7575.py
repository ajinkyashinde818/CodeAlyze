import sys
from io import StringIO
import unittest

doTest=0

def yn(n):
    if n==1:
        print("Yes")
    else:
        print("No")
    return

def resolve():
    readline=sys.stdin.readline


    s=readline().strip()
    q=int(readline().strip())
    hed=""
    btm=""
    rev=0
    for i in range(q):
        x=list(map(str, readline().strip().split()))
        if x[0]=="1": #rev
            if rev==0:
                rev=1
            else:
                rev=0
        elif x[0]=="2":
            if x[1]=="1": #head
                if rev==0:
                    hed = x[2] + hed
                else:
                    btm = btm + x[2]
            else: #bottom
                if rev==0:
                    btm = btm + x[2]
                else:
                    hed = x[2] + hed
    if rev==0:
        print(hed,end="")
        print(s,end="")
        print(btm)
    else:
        print(''.join(list(reversed(btm))),end="")
        print(''.join(list(reversed(s))),end="")
        print(''.join(list(reversed(hed))))
    return

if doTest==0:
    resolve()
    sys.exit()
