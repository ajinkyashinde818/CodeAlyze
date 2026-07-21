import sys
import copy
import  math
import bisect
from collections import *
from operator import itemgetter
"""
from fractions import gcd
def lcm(x, y):
    return (x * y) // gcd(x, y)
"""
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

def dfs(v):
    global ct
    visit[v][0] = True
    for next in g[v]:
        if visit[next][0]:
            continue
        else:
            visit[next][1] = visit[v][1] + 1
            if visit[next][1] >= 3:
                continue
            dfs(next)
n, m = na()
g = [[] for i in range(n)]
for i in range(m):
    a, b = na()
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)

visit = [[False, 0] for i in range(n)]
ct = 0
dfs(0)
print('POSSIBLE' if visit[n - 1][0] and visit[n - 1][1] <= 2 else 'IMPOSSIBLE')
