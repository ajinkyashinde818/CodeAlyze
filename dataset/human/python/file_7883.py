from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())


N,K,S = inpl()

if S != 10**9:
    ans = [S] * K + [10**9] * (N-K)
else:
    ans = [S] * K + [1] * (N-K)

print(" ".join(map(str,ans)))
