N, M = map(int, input().split())
edges = [[] for _ in range(N + 1)]

from collections import deque

for i in range(M):
  a, b = map(int, input().split())
  edges[a].append(b)
  edges[b].append(a)

queue = deque()
queue.append(1)
colors = ["white"] * (N + 1)

u = queue.popleft()
colors[u] = "black"

for edge in edges[u]:
  if colors[edge] != "black":
    queue.append(edge)

for i in range(len(queue)):
  u = queue.popleft()
  colors[u] = "black"
  for edge in edges[u]:
    if colors[edge] != "black":
      queue.append(edge)

for q in queue:
  if q == N:
    print("POSSIBLE")
    exit()

print("IMPOSSIBLE")
