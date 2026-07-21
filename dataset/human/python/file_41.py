from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpln(n): return list(int(sys.stdin.readline()) for i in range(n))

a,b,c,n = inpl()
res = 0
for i in range(3001):
    for j in range(3001):
        tmp = n - (i*a + j*b)
        if tmp < 0:
            break
        if tmp % c == 0:
            res += 1
print(res)
