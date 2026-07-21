import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
MAX = 10**18
MIN = -10**18
MOD = 998244353

k,s = map(int,input().split())

cnt = 0
for i in range(k+1):
    for j in range(k+1):
        l = s-i-j
        if l>=0 and l<=k:
            cnt += 1
print(cnt)
