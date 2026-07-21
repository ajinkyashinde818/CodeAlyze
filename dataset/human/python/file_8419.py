import sys
input = lambda: sys.stdin.readline().rstrip()

K, N = map(int, input().split())

A = list(map(int, input().split()))

max_dist = 0
for i in range(N-1):
    max_dist = max(max_dist, A[i+1]-A[i])

max_dist = max(max_dist, A[0]-(A[-1]-K))

print(K-max_dist)
