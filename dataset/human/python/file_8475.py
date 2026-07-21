import math

K, N = map(int, input().split())
A = list(map(int, input().split()))

max_dist = None

for i in range(N-1):
    dist = A[i+1] - A[i]
    if max_dist is None or max_dist < dist:
        max_dist = dist

dist = A[0] + K - A[N-1]
if max_dist < dist:
    max_dist = dist

print(K - max_dist)
