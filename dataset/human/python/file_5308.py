n,m=map(int,input().split())
from collections import defaultdict 
d=defaultdict(list)
from collections import deque 
for i in range(m):
    a,b=map(int,input().split())
    a-=1 
    b-=1 
    d[a].append(b)
    d[b].append(a)
q=[0]
dist=[0]*n 
vis=[0]*n 
vis[0]=1 
q=deque() 
q.append(0)
while q:
    t=q.popleft()
    for i in d[t]:
        if not vis[i]:
            vis[i]=1 
            dist[i]=dist[t]+1 
            q.append(i)
print('POSSIBLE' if dist[n-1]==2 else 'IMPOSSIBLE')
