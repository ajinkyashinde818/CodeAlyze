import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, log2
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd
from bisect import bisect

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, M = MAP()
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

for i in range(N-M+1):
	for j in range(N-M+1):  # 左上のますが(i, j)
		tmp_lis = []
		for k in range(M):
			tmp_lis.append(A[i+k][j:j+M])
		if tmp_lis == B:
			print("Yes")
			exit()
else:
	print("No")
