import sys
input = sys.stdin.readline

K, N = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
for i in range(N):
    if not ans:
        ans = min(abs(A[i - 1] - A[i]), abs(A[i] + (K - A[i + 1])))
    else:
        d = min(abs(K + A[i - 1] - A[i]), abs(A[i] + (K - A[i + 1]))) if i != N - \
            1 else min(abs(A[0] - A[i]), abs(A[i] + (K - A[0])))
        ans = min(ans, d)

print(ans)
