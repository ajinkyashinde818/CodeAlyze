import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

x = [0] * N
c = 0

for i in range(N):
    if A[i] < 0:
        c += 1
    x[i] = abs(A[i])

ans = sum(x)
if c % 2 == 1:
    ans -= min(x) * 2

print(ans)
