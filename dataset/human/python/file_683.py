import sys
import heapq
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 7)


def dist(x1, y1, x2, y2):
    dx = x1 - x2
    dy = y1 - y2
    return (dx ** 2 + dy ** 2) ** 0.5


xs, ys, xg, yg = map(int, input().split())
N = int(input())
XYR = [tuple(map(int, input().split())) for _ in range(N)]
edge = [[] for _ in range(N+2)]
#start = N
#goal = N+1

for i in range(N - 1):
    xi, yi, ri = XYR[i]
    for j in range(i + 1, N):
        xj, yj, rj = XYR[j]
        d = max(0, dist(xi, yi, xj, yj) - ri - rj)
        edge[i].append((j, d))
        edge[j].append((i, d))

for i in range(N):
    xi, yi, ri = XYR[i]

    ds = max(0, dist(xi, yi, xs, ys) - ri)
    edge[i].append((N, ds))
    edge[N].append((i, ds))

    dg = max(0, dist(xi, yi, xg, yg) - ri)
    edge[i].append((N + 1, dg))
    edge[N + 1].append((i, dg))

d = dist(xs, ys, xg, yg)
edge[N].append((N + 1, d))
edge[N + 1].append((N, d))


inf = 10**18
dist = [inf] * (N + 10)
dist[N] = 0
que = [(0, N)]
while que:
    c, s = heapq.heappop(que)
    if dist[s] < c:
        continue
    for t, cost in edge[s]:
        if dist[t] > dist[s] + cost:
            dist[t] = dist[s] + cost
            heapq.heappush(que, (dist[t], t))

print(dist[N + 1])
