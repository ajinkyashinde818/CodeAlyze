from heapq import *

xs, ys, xt, yt = [int(_) for _ in input().split()]
N = int(input())
XYR = [[xs, ys, 0]] + [[int(_) for _ in input().split()]
                       for _ in range(N)] + [[xt, yt, 0]]
G = [[0] * (N + 2) for _ in range(N + 2)]
for i in range(N + 1):
    for j in range(i + 1, N + 2):
        G[i][j] = G[j][i] = max(
            ((XYR[i][0] - XYR[j][0])**2 +
             (XYR[i][1] - XYR[j][1])**2)**0.5 - XYR[i][2] - XYR[j][2], 0)


def dijkstra(V, G, start):
    INF = float('inf')
    D = [INF for _ in range(V)]
    D[start] = 0
    H = [(0, start)]
    while H:
        du, u = heappop(H)
        if D[u] < du:
            continue
        for v, d in enumerate(G[u]):
            if D[v] > du + d:
                D[v] = du + d
                heappush(H, (D[v], v))
    return D


D = dijkstra(N + 2, G, 0)
print(D[-1])
