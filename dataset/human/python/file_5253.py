from collections import defaultdict

n, m = list(map(int, input().split()))

g = defaultdict(list)

for _ in range(m):
    a, b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

visited = [False]*n

q = [0]
visTime = 0
Found = False
while q and visTime < 2:
    
    nL = []
    for vert in q:
        visited[vert] = True
        for v in g[vert]:
            if v == n-1:
                Found = True
                break
            if not visited[v]:
                nL.append(v)
    if Found:
        break
    q = nL
    visTime += 1
    
print('POSSIBLE' if Found else 'IMPOSSIBLE')
