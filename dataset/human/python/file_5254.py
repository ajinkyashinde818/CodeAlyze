import queue
N, M = map(int, input().split())
G = [[] for _ in range(N)]

for i in range(M):
    a, b = map(lambda n: int(n) - 1, input().split())
    G[a].append(b)
    G[b].append(a)

def dfs(Graph, N, start):
    q = queue.Queue()
    dist = [-1] * N
    dist[start] = 0
    q.put(start)

    while not q.empty():
        v = q.get()
        if dist[v] >1:
            continue
        for u in G[v]:
            if dist[u] != -1:
                continue
            dist[u] = dist[v] + 1
            q.put(u)

    return dist
if dfs(G, N, 0)[-1] > 2 or dfs(G, N, 0)[-1] == -1:
    print('IMPOSSIBLE')
else:
    print('POSSIBLE')
