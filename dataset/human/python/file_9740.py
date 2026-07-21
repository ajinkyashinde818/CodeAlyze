from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
from bisect import bisect_left,bisect_right 
import sys,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,k = inpl()
a = inpl()
now = 1
r = [1]
fin = set([1])
while True:
    now = a[now-1]
    if now in fin:
        break
    r.append(now)
    fin.add(now)
ln = len(r)
for i in range(ln):
    if now == r[i]:
        fir = r[:i]
        nxx = r[i:]
        break
if k < i:
    print(fir[k])
else:
    k -= i
    m = len(nxx)
    print(nxx[k%m])
