import sys, math, itertools, bisect, copy, re

from collections import Counter, deque, defaultdict
from itertools import accumulate, permutations, combinations, takewhile, compress, cycle
from functools import reduce
from math import ceil, floor, log10, log2, factorial
from pprint import pprint

# 10倍速いらしい
input = sys.stdin.readline

INF = float('inf')
MOD = 10 ** 9 + 7
EPS = 10 ** -7
sys.setrecursionlimit(1000000)

# N = int(input())
# N,M = [int(x) for x in input().split()]
# V = [[0] * 100 for _ in range(100)]
# A = [int(input()) for _ in range(N)]
# DP = [[0] * 100 for _ in range(100)]
# DP = defaultdict(lambda: float('inf'))

N = int(input())
S = input().strip()
L = [0] * 2 * N
D = []

cnt = 1
D.append('L')
L = [cnt]
for i, s in enumerate(S):
    if i == 0:
        continue
    if s == 'W':
        if cnt % 2 == 1:
            cnt += 1
            D.append('L')
        else:
            cnt -= 1
            D.append('R')
    else:
        if cnt % 2 == 1:
            cnt -= 1
            D.append('R')
        else:
            cnt += 1
            D.append('L')
    L.append(cnt)

if len(list(filter(lambda x: x < 0, L))) > 0 or L[-1] != 0:
    print(0)
    sys.exit()

ans = 1
for i in range(1, 2 * N):
    if D[i] == 'R':
        ans *= L[i - 1]
        ans %= MOD

for i in range(1, N + 1):
    ans *= i
    ans %= MOD

print(ans)

# print(D)
# print(L)
