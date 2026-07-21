import sys
from collections import defaultdict
from collections import deque

n, m = map(int, input().split())

graph = defaultdict(list)

for _ in range(m):
    a, b = map(lambda x: int(x), input().split())
    graph[a].append(b)
    graph[b].append(a)

q = deque([1])
dist = [0] * (n + 1)
dist[1] = 0
curr = 0

while q and curr <= 2:
    node = q.popleft()
    after = graph[node]

    for a in after:
        if a == n:
            print("POSSIBLE")
            sys.exit()
        q.append(a)
        dist[a] = dist[node] + 1

    curr = dist[a]

print("POSSIBLE" if dist[n] == 1 or dist[n] == 2 else "IMPOSSIBLE")
