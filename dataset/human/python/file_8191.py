from collections import defaultdict, deque
import sys
import heapq
import bisect
import itertools
import queue
import copy
import time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7

def inp(): return int(sys.stdin.readline())

def inpl(): return list(map(int, sys.stdin.readline().split()))

def inpl_str(): return list(sys.stdin.readline().split())

k, s = inpl()
ans = 0
for x in range(k+1):
    for y in range(k+1):
        z = s - x - y
        if 0 <= z and z <=k:
            ans += 1
print(ans)
