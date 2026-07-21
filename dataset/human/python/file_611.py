from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,copy
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n = inp()
a = inpl()
cnt = 0
for i in range(n):
    if a[i] < 0:
        cnt += 1
a = [abs(x) for x in a]
a.sort()
if cnt%2:
    a[0] = -a[0]
print(sum(a))
