from collections import Counter,defaultdict,deque
from heapq import heappop,heappush
from bisect import bisect_left,bisect_right 
import sys,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

import random
n = inp()
a = inpl()
b = inpl()
c = [0] * (n+1)
for i in range(n):
    c[a[i]] += 1
    c[b[i]] += 1
if max(c) > n:
    print('No')
    quit()
q = deque([])
for i in range(n):
    if a[i] == b[i]:
        q.append(i)
while q:
    now = q.popleft()
    nx = random.randint(0,n-1)
    if a[now] != b[nx] and a[nx] != b[now]:
        b[now],b[nx] = b[nx],b[now]
    else: q.append(now)
print('Yes')
print(*b)
