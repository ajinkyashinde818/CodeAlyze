n,m=map(int,input().split())
ab=[list(map(int, input().split())) for _ in range(m)]

graph = [[] for _ in range(n)]
for v in ab:
    graph[v[0]-1].append(v[1]-1)
    graph[v[1]-1].append(v[0]-1)
# print(graph)

from collections import deque

queue = deque([0])
d = [10**6] * n
d[0] = 0
while queue:
    v = queue.popleft()
    for i in graph[v]:
        if d[i]==10**6:
            d[i] = d[v] + 1
            queue.append(i)
# print(d)

print('POSSIBLE' if d[n-1]<=2 else 'IMPOSSIBLE')
