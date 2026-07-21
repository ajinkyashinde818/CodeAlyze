n,m = map(int, input().split())

from collections import defaultdict 
V = defaultdict(list)

for _ in range(m):
    a,b = map(int, input().split())
    V[a].append(b)
    V[b].append(a)

from collections import deque

def bfs(u):
    queue = deque([u])
    d = [None] * (n+1) # uからの距離の初期化
    d[u] = 0 # 自分との距離は0
    while queue:
        v = queue.popleft()
        for i in V[v]:
            if d[i] is None:
                d[i] = d[v] + 1
                queue.append(i)
    return d

b1 = bfs(1)
if b1[n] ==2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
