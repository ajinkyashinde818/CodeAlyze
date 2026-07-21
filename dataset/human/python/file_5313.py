import bisect
import heapq
import itertools
import math
import operator
import os
import re
import string
import sys
from collections import Counter, deque, defaultdict
from copy import deepcopy
from decimal import Decimal
from fractions import gcd
from functools import lru_cache, reduce
from operator import itemgetter, mul, add, xor

import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N, M = list(map(int, sys.stdin.readline().split()))
AB = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

graph = [[] for _ in range(N + 1)]
for a, b in AB:
    graph[a].append(b)
    graph[b].append(a)

que = deque()
que.append((1, 0))
ok = False
seen = [[False] * (N + 1), [False] * (N + 1)]
while que:
    v, d = que.popleft()
    if v == N and d == 2:
        ok = True
        break
    if d >= 2:
        continue
    for u in graph[v]:
        if not seen[d][u]:
            seen[d][u] = True
            que.append((u, d + 1))
if ok:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
