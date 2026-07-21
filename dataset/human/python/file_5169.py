from collections import deque

N,M=map(int,input().split())
G=[[]for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
dist=[-1]*N
d=deque()
dist[0]=0
d.append(0)
while(len(d)!=0):
    v=d[0]
    d.popleft()
    for nv in G[v]:
        if(dist[nv]!=-1):
            continue
        dist[nv]=dist[v]+1
        d.append(nv)
if(dist[N-1]==2):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
