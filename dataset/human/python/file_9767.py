from collections import deque

N, K = map(int, input().split())
A = list(map(int, input().split()))
Q = deque()
Q.append(0)

Seen = [-1] * N
Seen[0] = 0
loop = 0
point = 0
while True:
    now = Q.popleft()
    nex = A[now]
    nex -= 1
    if Seen[nex] == -1:
        Seen[nex] = Seen[now] + 1
        Q.append(nex)
    elif Seen[nex] != -1:
        first = Seen[nex]
        loop = Seen[now] - Seen[nex] + 1
        point = nex
        break

if first > K:
    ind = Seen.index(K)
    print(ind+1)
    exit()

p = (K - first) % loop
Q.clear()
Q.append(point)
ans = point
while p > 0:
    no = Q.popleft()
    ans = A[no]
    ans -= 1
    Q.append(ans)
    p -= 1
print(ans + 1)
