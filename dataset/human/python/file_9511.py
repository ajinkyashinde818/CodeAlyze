import sys

N, K = map(int, input().split())
A = list(map(int, sys.stdin.readline().rsplit()))
B = [-1] * N

if K <= N:
    now = 0
    for i in range(K):
        now = A[now] - 1
    print(now + 1)
    exit()

now = 0
for i in range(N):
    if B[now] == -1:
        B[now] = i
        now = A[now] - 1
    else:
        tmp = (K - B[now]) % (i - B[now])
        for i in range(tmp):
            now = A[now] - 1
        print(now + 1)
        exit()
