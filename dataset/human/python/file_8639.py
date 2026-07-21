import sys
from sys import exit
from math import gcd, factorial, ceil, floor, sqrt
from bisect import bisect_left, bisect_right
from copy import deepcopy
from heapq import heapify, heappop, heappush
from itertools import permutations, combinations, product, accumulate
from collections import defaultdict, deque
sys.setrecursionlimit(10**7)

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

K, N = mi()
A = li()

ls = []
for i in range(N-1):
    ls.append(A[i+1] - A[i])
ls.append(A[0] + (K - A[-1]))
print(K - max(ls))
