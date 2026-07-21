from collections import deque
n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

q = deque([1])
visited = [False] * (n+1)
d = [0] * (n+1)

while q:
    now = q.popleft()
    visited[now] = True
    for i in graph[now]:
        if visited[i]:
            pass
        else:
            q.append(i)
            d[i] = d[now] + 1
if d[n] == 2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
