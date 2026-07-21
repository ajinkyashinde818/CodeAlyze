from collections import deque


n, m = map(int, input().split())
path = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    path[a-1].append(b-1)
    path[b-1].append(a-1)



from collections import deque


def dfs(path, start):
    que = deque([(start, 0)])
    dist = [float('inf')] * n
    while que:
        cur, c = que.popleft()
        c += 1
        for nxt in path[cur]:
            if c < dist[nxt]:
                dist[nxt] = c
                que.append((nxt, c))
    return dist



dist = dfs(path, 0)
if dist[-1] == 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
