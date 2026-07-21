import bisect
import copy
import heapq
import math
import sys
from collections import *
from itertools import accumulate, combinations, permutations, product
from math import gcd
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

n,k=map(int,input().split())
a=list(map(int,input().split()))

itta=[0]*(n+1)
now=1
cnt=1
while itta[now]==0:
    itta[now]=cnt
    now=a[now-1]
    if cnt==k:
        print(now)
        quit()
    cnt+=1

# print(itta)
# print(now)
# print(cnt)

k-=itta[now]-1
k%=cnt-itta[now]

while k>0:
    k-=1
    now=a[now-1]

print(now)
