from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

k,n = inpl()
a = inpl()
b = []
for i in range(1,n):
    b.append(abs(a[i] - a[i-1]))
b.append(k-a[-1] + a[0])
b.sort()
print(sum(b) - b[-1])
