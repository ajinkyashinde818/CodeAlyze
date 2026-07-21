N,M=list(map(int,input().strip().split(' ')))
graph=[[] for i in range(N)]
for _ in range(M):
    a,b=list(map(int,input().strip().split(' ')))
    a-=1
    b-=1
    graph[a]+=[b]
    graph[b]+=[a]
from collections import deque

q=deque([0])

visit=[0]*N
level=[0 for i in range(N)]
level[N-1]=3
parent=[-1]*N
while q:
    v=q.popleft()
    visit[v]=1
    for adj in graph[v]:
        if adj!=parent[v] and visit[adj]==0:
            parent[adj]=v
            visit[adj]=1
            q+=[adj]
            level[adj]=level[v]+1
if level[N-1]<=2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
