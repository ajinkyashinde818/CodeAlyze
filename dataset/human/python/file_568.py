import copy
import math
import string
import heapq
import bisect
import sys
sys.setrecursionlimit(10**7)

N = int(input())
A = list(map(int,input().split()))
mc = 0
for i in range(N):
    if A[i] < 0:
        mc += 1
    A[i] = abs(A[i])
A.sort()
ans = 0
for i in range(N):
    if i == 0 and mc % 2 == 1:
        ans -= A[i]
    else:
        ans += A[i]
print(ans)
