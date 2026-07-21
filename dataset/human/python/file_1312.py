import sys
input = sys.stdin.readline

N = int(input())
A = [int(v) for v in input().split()]
p = sum(A)
L = [0] * (N + 1)

for i in range(N):
    L[i + 1] = L[i] + A[i]

ans = 10 ** 18
for i in range(N - 1):
    t = L[i + 1] - L[0]

    ans = min(ans, abs(t - p + t))

print(ans)
