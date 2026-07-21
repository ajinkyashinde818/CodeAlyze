from collections import deque


def bfs(adj, s, t, use):
    if s == t:
        return 1
    que = deque()
    seen = [0] * len(adj)
    que.append(s)
    seen[s] = 1
    while que:
        v = que.popleft()
        for u, cost in adj[v]:
            if seen[u] == 0 and use[cost] == 1:
                if u == t:
                    return 1
                seen[u] = 1
                que.append(u)
    return 0


N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

adj = [[] for _ in range(51)]
for i in range(51):
    for j in range(1, i+1):
        adj[i].append((i%j, j))

use = [1] * 51
use[0] = 0
for i in range(50, 0, -1):
    use[i] = 0
    for ai, bi in zip(a, b):
        if not bfs(adj, ai, bi, use):
            use[i] = 1
            break

if sum(use) == 50:
    print(-1)
    exit()

print(sum([(2**i) * use[i] for i in range(51)]))
