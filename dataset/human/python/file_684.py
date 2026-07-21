from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from functools import reduce


sys.setrecursionlimit(2147483647)
INF = 10 ** 13
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007


sx, sy, gx, gy = LI()
n = I()
circles = [[sx, sy, 0]] + LIR(n) + [[gx, gy, 0]]
G = [[0] * (n + 2) for _ in range(n + 2)]
for i in range(n + 2):
    for j in range(i + 1, n + 2):
        G[i][j] = G[j][i] = \
        max(0, ((circles[i][0] - circles[j][0]) ** 2 + (circles[i][1] - circles[j][1]) ** 2) ** 0.5 - circles[i][2] - circles[j][2])


def dijkstra(graph, start=0):
    que = [(0, start)]
    dist = [INF] * (n + 2)
    dist[start] = 0
    while que:
        min_dist, u = heappop(que)
        if min_dist > dist[u]:
            continue
        for v, c in enumerate(graph[u]):
            if dist[u] + c < dist[v]:
                dist[v] = dist[u] + c
                heappush(que, (dist[u] + c, v))
    return dist


print(dijkstra(G, start=0)[-1])
