import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

S = input()
S = S[::-1]
word = ["dream", "dreamer", "erase", "eraser"]
flag = 0
tmp = ""
while 1:
	if tmp == S:
		print("NO")
		break
	tmp = S
	for w in word:
			# print(S)
			# print(w)
			if len(S) <= 4:
				print("NO")
				flag = 1
			elif S[:5] == w[::-1]:
				if len(S) == 5:
					print("YES")
					flag = 1
					break
				else:
					S = S[5:]
			elif S[:6] == w[::-1]:
				if len(S) == 6:
					print("YES")
					flag = 1
					break
				else:
					S = S[6:]
			elif S[:7] == w[::-1]:
				if len(S) == 7:
					print("YES")
					flag = 1
					break
				else:
					S = S[7:]
	if flag == 1:
		break
