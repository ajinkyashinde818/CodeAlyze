import sys
sys.setrecursionlimit(10**8)
n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a-=1; b-=1
    g[a].append(b)
    g[b].append(a)

dist = [float('inf')] * n
def dfs(s, p, depth):
    if depth>2: return
    dist[s] = min(dist[s], depth)
    for to in g[s]:
        if to==p: continue
        if dist[to] < dist[s]+1: continue
        dfs(to, s, depth+1)

dfs(0, -1, 0)

if dist[n-1] <= 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
