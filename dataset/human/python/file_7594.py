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

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

S = input()
S = deque(S)
Q = INT()
flag = 1  # 1で正順
for _ in range(Q):
	q = input().split()
	if len(q) == 1:  # 前後入れ替え
		flag *= -1
	else:  # 先頭 or 末尾に追加
		_, F, C = q
		if F == "1" and flag == 1 or F == "2" and flag == -1:
			S.appendleft(C)
		else:
			S.append(C)
ans = "".join(S)
if flag == -1:
	ans = ans[::-1]
print(ans)
