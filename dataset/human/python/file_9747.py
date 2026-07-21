from collections import deque

N, K = map(int, input().split())
A = list(map(int, input().split()))

check = [-1] * N
q = deque([1])
now = A[0]
check[0] = 0

for i in range(K):
    if check[now - 1] != -1:
        break
    check[now - 1] = i + 1
    q.append(now)
    now = A[now - 1]

x = check[now - 1]

if x > K:
    ans = q[K]
else:
    r = list(q)[x:]
    ans = q[(K - x) % len(r) + x]

print(ans)
