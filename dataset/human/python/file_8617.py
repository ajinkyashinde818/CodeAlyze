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
al=[chr(ord('a') + i) for i in range(26)]

k,n=map(int,input().split())
a=list(map(int,input().split()))
# a.sort()
ans=float('inf')
for i in range(n-1):
    ans=min(ans, k-(a[i+1]-a[i]))
ans=min(ans,k-(a[0]+k-a[n-1]))
print(ans)
