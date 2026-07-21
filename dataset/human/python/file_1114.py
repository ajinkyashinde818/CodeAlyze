import bisect
import collections
import copy
import functools
import heapq
import math
import sys
from collections import deque
from collections import defaultdict
from fractions import Fraction
input = sys.stdin.readline
sys.setrecursionlimit(10**9)
INF = float("inf")
MOD = 10**9+7

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

B.reverse()

for i in range(N):
    if A[i] == B[i]:
        k = A[i]
        break
else:
    print("Yes")
    print(*B)
    exit()

possible = []
impossible = []
for i in range(N):
    if A[i] != k and B[i] != k:
        possible.append(i)
    elif A[i] == k and B[i] == k:
        impossible.append(i)

for i in impossible:
    if not possible:
        print("No")
        exit()
    j = possible.pop()
    B[i],B[j] = B[j],B[i]

print("Yes")
print(*B)
