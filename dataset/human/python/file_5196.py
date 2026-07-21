import sys
input = sys.stdin.readline
from collections import deque


n, m = map(int, input().split())

GRAPH = {i:[] for i in range(1, n + 1)}
for _ in range(m):
    a, b = map(int, input().split())
    GRAPH[a].append(b)
    GRAPH[b].append(a)

DISTANCE = {i:-1 for i in range(1, n + 1)}
DISTANCE[1] = 0
QUEUE = deque([1])
while QUEUE:
    now = QUEUE.popleft()
    for v in GRAPH[now]:
        if DISTANCE[v] != -1:
            continue
        DISTANCE[v] = DISTANCE[now] + 1
        QUEUE.append(v)

print("POSSIBLE" if DISTANCE[n] == 2 else "IMPOSSIBLE")
