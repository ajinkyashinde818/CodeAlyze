from collections import deque
from heapq import heapify,heappop,heappush,heappushpop
from copy import copy,deepcopy
from itertools import permutations,combinations
from collections import defaultdict,Counter
from bisect import bisect_left,bisect_right
# from math import gcd,ceil,floor,factorial
from fractions import gcd
from functools import reduce
from pprint import pprint

def myinput():
    return map(int,input().split())

def mylistinput(n):
    return [ list(myinput()) for _ in range(n) ]

def mycol(data,col):
    return [ row[col] for row in data ]

def mysort(data,col,reverse_flag):
    data.sort(key=lambda x:x[col],reverse=reverse_flag)
    return data

def mymax(data):
    M = -1*float("inf")
    for i in range(len(data)):
        m = max(data[i])
        M = max(M,m)
    return M

def mymin(data):
    m = float("inf")
    for i in range(len(data)):
        M = min(data[i])
        m = min(m,M)
    return m

def myoutput(ls,space=True):
    if space:
        if len(ls)==0:
            print(" ")
        elif type(ls[0])==str:
            print(" ".join(ls))
        elif type(ls[0])==int:
            print(" ".join(map(str,ls)))
        else:
            print("Output Error")
    else:
        if len(ls)==0:
            print("")
        elif type(ls[0])==str:
            print("".join(ls))
        elif type(ls[0])==int:
            print("".join(map(str,ls)))
        else:
            print("Output Error")

n = int(input())
a = list(myinput())
b = list(map(abs,a))

ind = b.index(min(b))

c = deepcopy(a)
# print(c)
i = 0
while i<(ind):
    s = c[i]
    t = c[i+1]
    if s>=0 and t>=0:
        i += 2
    elif s>=0 and t<=0:
        i += 1
    elif s<=0 and t>=0:
        c[i] = -1*s
        c[i+1] = -1*t
        i += 1
    elif s<=0 and t<=0:
        c[i] = -1*s
        c[i+1] = -1*t
        i += 2
# print(c)
d = c[::-1]
# print(d)
i = 0
while i<(n-ind-1):
    s = d[i]
    t = d[i+1]
    if s>=0 and t>=0:
        i += 2
    elif s>=0 and t<=0:
        i += 1
    elif s<=0 and t>=0:
        d[i] = -1*s
        d[i+1] = -1*t
        i += 1
    elif s<=0 and t<=0:
        d[i] = -1*s
        d[i+1] = -1*t
        i += 2
# print(d)

ans = sum(d)
print(ans)
