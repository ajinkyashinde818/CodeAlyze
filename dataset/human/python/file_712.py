import sys
input=sys.stdin.readline
from heapq import heappush, heappop

def dijkstra(x,Route):
    n=len(Route)
    D=[float('inf')]*n
    D[x]=0
    hq=[(0,x)]
    while hq:
        c,u=heappop(hq)
        if D[u]<c:
            continue
        for v,cost in Route[u]:
            if D[u]+cost<D[v]:
                D[v]=D[u]+cost
                heappush(hq,(D[v],v))
    return D

def dist(V1,V2):
    return max(0,((V2[0]-V1[0])**2+(V2[1]-V1[1])**2)**0.5-(V1[2]+V2[2]))

sx,sy,gx,gy=map(int,input().split())
n=int(input())
V=[(sx,sy,0)]+[tuple(map(int,input().split())) for _ in range(n)]+[(gx,gy,0)]
Edges=[[] for _ in range(n+2)]
for i in range(n+1):
    for j in range(i+1,n+2):
        d=dist(V[i],V[j])
        Edges[i].append((j,d))
        Edges[j].append((i,d))
print(dijkstra(0,Edges)[-1])
