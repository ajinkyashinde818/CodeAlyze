import sys
input = sys.stdin.readline

def Dijkstra(N, edges, s):
    from heapq import heappush, heappop, heapify
    dist = [10**18 for _ in range(N)]
    dist[s], h = 0, [[0, s]]
    while (len(h)):
        p = heappop(h)
        d, v = p[0], p[1]
        if d > dist[v]:
            continue
        for i in range(len(edges[v])):
            u = edges[v][i]
            if d + 1 < dist[u]:
                dist[u] = d + 1
                heappush(h, [dist[u], u])
    return dist

N, M = map(int, input().split())
es = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    es[a].append(b)
    es[b].append(a)
dist = Dijkstra(N, es, 0)
if dist[N - 1] == 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
