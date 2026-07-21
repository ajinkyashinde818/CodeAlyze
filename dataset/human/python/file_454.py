import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

ans = 0
m = 10 ** 9 + 1
for i in range(N - 1):
    if A[i] < 0:
        A[i] = -A[i]
        A[i + 1] = -A[i + 1]
    ans += A[i]
    if A[i] < m:
        m = A[i]

if A[N - 1] < 0:
    m = min(m, abs(A[N - 1]))
    ans += abs(A[N - 1])
    ans -= 2 * m
else:
    ans += A[N - 1]
print(ans)
