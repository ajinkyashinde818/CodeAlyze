import sys
from collections import deque, defaultdict
import copy
import bisect
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
import math

N = int(input())
A = list(map(int, input().split()))
zeros = 0
minus = 0
B = []
for i in range(len(A)):
	if A[i] < 0:
		minus += 1
	elif A[i] == 0:
		zeros += 1
	B.append(abs(A[i]))


if zeros > 0:
	print(sum(B))
elif minus % 2 == 0:
	print(sum(B))
else:
	print(sum(B) - 2*min(B))
