from collections import deque
N, M = map(int, input().split())
lst = [[] for _ in range(N + 1)]
dist = [float("inf")]*(N+1)
dist[1] = 0
for _ in range(M):
    a, b = map(int, input().split())
    lst[a].append(b)
    lst[b].append(a)

q = deque()
q.append(1)

while q:
    now = q.popleft()

    for itm in lst[now]:
        if dist[itm] > dist[now]:
            q.append(itm)
            dist[itm] = dist[now] + 1
print("POSSIBLE") if dist[N] <= 2 else print("IMPOSSIBLE")
