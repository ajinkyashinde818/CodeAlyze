import bisect
import copy
import heapq
import math
import sys
from collections import *
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
sys.setrecursionlimit(500000)
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

dic={}

n,m=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(m)]

for i in range(m):
    a,b=ab[i]
    if a==1:
        dic[b]=1

# print(dic)
for i in range(m):
    a,b=ab[i]
    if b==n and a in dic:
        print("POSSIBLE")
        break
else:
    print("IMPOSSIBLE")
