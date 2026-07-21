import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product, groupby
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
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

S = deque(input())

ans = 0
while S:
	if len(S) == 1:
		S.pop()
	elif S[0] == S[-1]:
		S.popleft()
		S.pop()
	else:
		if S[0] == "x":
			S.append("x")
			ans += 1
		elif S[-1] == "x":
			S.appendleft("x")
			ans += 1
		else:
			print(-1)
			break
else:
	print(ans)
