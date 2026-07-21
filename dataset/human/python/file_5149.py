n, m = map(int, input().split())
graph = {i: [] for i in range(1, n + 1)}
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

import queue
voi = [100] * (n + 1)
tf = [False] * (n + 1)
def bfs(v):
    q = queue.Queue()
    q.put(v)
    tf[v] = True
    voi[v] = 0
    while not q.empty():
        now = q.get()
        for nex in graph[now]:
            if tf[nex]:
                continue
            q.put(nex)
            voi[nex] = voi[now] + 1
            tf[nex] = True

bfs(1)
if voi[n] <= 2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
