from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,s = inpl()
res = 0
for i in range(n+1):
    for j in range(n+1):
        if 0 <= s - (i+j) <= n:
            res += 1
print(res)
