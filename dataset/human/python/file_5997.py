from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

N = inp()
AA = inpl()
BB = inpl()
CC = inpl()

ans = sum(BB)
for i in range(N-1):
    if AA[i+1] == AA[i]+1:
        ans += CC[AA[i]-1]

print(ans)
