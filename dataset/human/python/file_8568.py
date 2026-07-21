import sys
from pprint import pprint

K, N = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))

d = []
for i in range(1, N):
    d.append(min(A[i] - A[i-1], K - A[i] + A[i-1]))
d.append(min(A[N-1] - A[0], K - A[N-1] + A[0]))

print(K - max(d))
