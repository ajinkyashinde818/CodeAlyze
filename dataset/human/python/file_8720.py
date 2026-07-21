import sys

K, N = map(int, input().split())
A = list(map(int, sys.stdin.readline().split()))

max_diff = A[1] - A[0]

for i in range(N - 1):
    diff = A[i + 1] - A[i]
    if diff > max_diff:
        max_diff = diff

diff = A[0] + (K - A[N - 1])
if diff > max_diff:
    max_diff = diff

ans = K - max_diff

print(ans)
