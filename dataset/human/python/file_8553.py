import sys
input = sys.stdin.readline
from collections import defaultdict, Counter

K, N = map(int, input().split())
A = list(map(int, input().split()))
M = A[0]+K-A[-1]
for i in range(N-1):
    M = max(M, A[i+1]-A[i])
print(K-M)
