import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, M = MAP()
path = [LIST() for _ in range(M)]

graph = [[] for _ in range(N)]

for a, b in path:
	graph[a - 1].append(b - 1)
	graph[b - 1].append(a - 1)

for i in range(len(graph[0])):
	a = sorted(graph[graph[0][i]])
	if a[len(a) - 1] == N - 1:
		print("POSSIBLE")
		exit()

print("IMPOSSIBLE")
