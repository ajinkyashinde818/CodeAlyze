N, M = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(M)]

import heapq
from collections import defaultdict
nodes = defaultdict(list)


for e in edges:
    nodes[e[0] - 1].append((1, e[1] - 1))
    nodes[e[1] - 1].append((1, e[0] - 1))


INF = float('inf')

def dijkstra(x):
    que = []
    heapq.heapify(que)
    dist = [INF for _ in range(N)]
    dist[x] = 0
    heapq.heappush(que, (0, x))

    while que:
        p = heapq.heappop(que)
        v = p[1]
        if dist[v] < p[0]:
            continue
        for e in nodes[v]:
            if dist[e[1]] > dist[v] + e[0]:
                dist[e[1]] = dist[v] + e[0]
                heapq.heappush(que, (dist[e[1]], e[1]))

    return dist

dist = dijkstra(0)

if dist[-1] <= 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
