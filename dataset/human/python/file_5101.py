n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

from collections import defaultdict
graph = defaultdict(list)
for i in range(m):
    a = ab[i][0] - 1
    b = ab[i][1] - 1
    graph[a].append(b)
    graph[b].append(a)

dist = [float('inf')] * n
dist[0] = 0

stack = []
for target in graph[0]:
    dist[target] = 1
    stack.append(target)

for s in stack:
    for target in graph[s]:
        dist[target] = min(dist[target], 2)

if dist[n - 1] <= 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
