n, m = map(int, input().split())
G = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)


from collections import deque
q = deque([[0, 0]])
visited = [0] * n
visited[0] = 1
while q:
    node, c = q.popleft()
    if c > 2:
        continue
    if node == n-1:
        print('POSSIBLE')
        break

    for to in G[node]:
        if visited[to] == 1:
            continue
        visited[to] = 1
        q.append([to, c+1])
else:
    print('IMPOSSIBLE')
