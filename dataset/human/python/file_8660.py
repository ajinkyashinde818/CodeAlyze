import sys
int1 = lambda x: int(x) - 1
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

K, N = map(int, readline().split())
A = list(map(int, readline().split()))
A_ = [a + K for a in A]

ans = 10**9 + 7
min1, max1 = min(A), max(A)

for i in range(N):
    if A[i - 1] - A[i] > 0:
        CW = A[i - 1] - A[i]
    else:
        CW = A[i] + K - A[i - 1]

    if i != N - 1:
        if A[i] - A[i + 1] > 0:
            CCW = A[i] - A[i + 1]
        else:
            CCW = A[i] + K - A[i + 1]
    else:
        CCW = A[i] - A[0]

    ans = min(ans, min(CW, CCW))

print(ans)
