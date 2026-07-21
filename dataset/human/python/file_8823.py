import sys

K, N = map(int, sys.stdin.readline().rstrip().split())
A = list(map(int, sys.stdin.readline().rstrip().split()))

distances = [0] * N
for i in range(N):
    if i == 0:
        distances[i] = A[i] + K - A[-1]
    else:
        distances[i] = A[i] - A[i - 1]

minimum_distance = K - max(distances)
print(minimum_distance)
