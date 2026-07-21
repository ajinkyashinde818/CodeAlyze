from collections import deque
import heapq
import itertools
import math

k,n=map(int,input().split())
a=list(map(int,input().split()))
sum=0
max_root=0
tmp = k-(a[-1]-a[0])
max_root=tmp
sum+=tmp
for i in range(len(a)-1):
    tmp = a[i+1]-a[i]
    if tmp > max_root:
        max_root=tmp
    sum+=tmp

print(k-max_root)
