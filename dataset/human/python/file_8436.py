import copy
import math
import string
import heapq
import bisect
import sys
sys.setrecursionlimit(10**7)

K,N = map(int,input().split())
A = list(map(int,input().split()))

a = min(abs(A[N-1]-A[0]),K-abs(A[N-1]-A[0]))
for i in range(N-1):
    a = max(a,abs(A[i]-A[i+1]))
print(K-a)
