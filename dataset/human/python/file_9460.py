import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections

n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
    a[i]-=1

roop = [0]
for i in range(3*n):
    roop.append(a[roop[i]])
cnt =[0]*n
d = []
for i in range(len(roop)):
    cnt[roop[i]]+=1
    if cnt[roop[i]]>=3 and cnt[roop[i]]<4:
        d.append(roop[i])
for i in range(len(roop)):
    if roop[i] == d[0]:
        check = i
        break
if check == 0:
    k%=len(d)
    print(d[k]+1)
else:
    if k<check + len(d):
        print(roop[k]+1)
    else:
        k-=check
        k%=len(d)
        print(d[k]+1)
