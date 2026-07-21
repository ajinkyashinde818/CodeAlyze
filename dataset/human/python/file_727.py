import sys
from math import sqrt
input = sys.stdin.readline
from heapq import heappop, heappush
xs, ys, xt, yt = map(int, input().split())
N = int(input())
INF = float('inf')
cost = [[INF] * (N + 2) for i in range(N + 2)]
D = [(xs, ys, 0)]
for i in range(N):
    x, y, r = map(int, input().split())
    D.append((x, y, r))
D.append((xt, yt, 0))

for i in range(N + 2):
    for j in range(i + 1, N + 2):
        k = max(0, sqrt((D[i][0] - D[j][0]) ** 2 + (D[i][1] - D[j][1]) ** 2) - D[i][2] - D[j][2])
        cost[i][j] = k
        cost[j][i] = k

visit = [0] * (N + 2)
visit[0] = 1
d = [INF] * (N + 2)
d[0] = 0
que = [(0, 0)]
while que:
    dist, v = heappop(que)
    if d[v] < dist:
        continue
    if v == N + 1:
        print(d[v])
        exit()
    visit[v] = 1
    for w in range(N + 2):
        if visit[w] == 0 and w != v and d[w] > d[v] + cost[v][w]:
            d[w] = d[v] + cost[v][w]
            heappush(que, (d[w], w))
