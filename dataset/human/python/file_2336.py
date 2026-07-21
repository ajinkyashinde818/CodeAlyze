import math, sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import lru_cache
from heapq import heapify, heappop, heappush
from itertools import accumulate, combinations, permutations
input = sys.stdin.readline
mod = 10**9 + 7
ns = lambda: input().strip()
ni = lambda: int(input().strip())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

d, g = nm()
pc = [nl() for _ in range(d)]
costs = []
for i in range(2**d):
    binary = '0'*(d-len(bin(i)[2:])) + bin(i)[2:]
    #print(binary)
    point = 0
    num = 0
    remain = [100 * len(pc), 0]
    for j, digit in enumerate(binary):
        if digit == '1':
            point += 100 * (j + 1) * pc[j][0] + pc[j][1]
            num += pc[j][0]
        if digit == '0':
            remain = [100 * (j + 1), pc[j][0]]
    if point < g:
        num += math.ceil(min((g - point) / remain[0], remain[1]))
        point = point + min(g - point, remain[0] * remain[1])
    costs.append([point, num, binary])
    #print(binary, [point, num], remain)
costs.sort(key=lambda x: (x[1], x[0]))
#print(costs)
for value in costs:
    if value[0] >= g:
        print(value[1])
        exit()
