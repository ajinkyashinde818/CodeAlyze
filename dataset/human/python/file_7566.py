import sys
from collections import *
import heapq
import math
import bisect
from itertools import permutations,accumulate,combinations,product
from fractions import gcd
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
mod=pow(10,9)+7

s=input()
q=int(input())
query=[input().split() for i in range(q)]
now=0
d=deque(s)
# print(d)
for i in range(q):
    if query[i][0]=="1":
        now+=1
    else:
        if now%2==0:
            if query[i][1]=="1":
                d.appendleft(query[i][2])
            else:
                d.append(query[i][2])
        else:
            if query[i][1]=="1":
                d.append(query[i][2])
            else:
                d.appendleft(query[i][2])
if now%2==1:
    d.reverse()
print("".join(d))
