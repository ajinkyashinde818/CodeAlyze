def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]

from collections import defaultdict, deque, Counter
from sys import exit
import heapq
import math
import copy
from bisect import bisect_left, bisect_right

import sys
sys.setrecursionlimit(1000000000)

N, M = map(int, input().split())
A = [0]*N
B = [0]*M

for i in range(N):
	A[i] = input()
for i in range(M):
	B[i] = input()

ans = False
for sy in range(N-M+1):
	for sx in range(N-M+1):
		flag = True
		for iy in range(M):
			if B[iy] != A[sy+iy][sx:sx+M]:
				flag = False
				break
		if flag:
			ans = True
			break

if ans:
	print("Yes")
else:
	print("No")
