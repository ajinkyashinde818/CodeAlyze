import sys
sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline
from itertools import permutations,  combinations, accumulate
from functools import *
from collections import deque, defaultdict, Counter
from heapq import heapify, heappop, heappush, heappushpop

INF = float('inf')
NIL = - 1


N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

total = 0
tmp_num = -1

for i in range(N):
    num = A[i]
    total += B[num-1]

    if tmp_num + 1 == num:
        total += C[tmp_num-1]
    tmp_num = num

print(total)
