import sys
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
for i in range(N):
    A[i] -= 1
first = [-1] * N


if K < 2 * N:
    now = 0
    for i in range(K):
        now = A[now]
    print(now + 1)
    sys.exit()

first[0] = 0
now = 0
while True:
    next = A[now]
    if first[next] == -1:
        first[next] = first[now] + 1
        now = next
    else:
        K -= first[next]
        loop = first[now] + 1 - first[next]
        K %= loop
        now = next
        for i in range(K):
            now = A[now]
        print(now + 1)
        sys.exit()
