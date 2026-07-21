n,m=map(int,input().split())
g=[[] for _ in range(n)] 
for _ in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)

from collections import deque 

def bfs(u, g): #uからの最短経路を求める
    u-=1
    queue = deque([u])
    d=[-1]*n
    d[u]=0
    while queue:
        v=queue.popleft()
        for i in g[v]:
            if d[i] is -1:
                d[i]=d[v]+1
                queue.append(i)
    return d

d = bfs(1,g) #dは頂点sからの最短経路
if d[-1]==2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
