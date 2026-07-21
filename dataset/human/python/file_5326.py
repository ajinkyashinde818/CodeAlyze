from collections import deque

n, m = map(int, input().split())
adj = [[] for i in range(n + 1)]
for _ in range(m):
	a, b = map(int, input().split())
	adj[a].append(b)
	adj[b].append(a)
dist = [-1 for i in range(n + 1)]
dist[1] = 0
Q = deque()
Q.append(1)
while len(Q) > 0:
	u = Q.popleft()
	for v in adj[u]:
		if dist[v] != -1:
			continue
		dist[v] = dist[u] + 1
		Q.append(v)
if dist[n] == 2:
	print("POSSIBLE")
else:
	print("IMPOSSIBLE")
