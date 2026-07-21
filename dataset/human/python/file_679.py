import math
import heapq
def dijkstra(s,m,n):
    visited=[0]*n
    d=[float("inf")]*n
    d[s]=0
    while True:
        mincost=float("inf")
        for i in xrange(n):
            if visited[i]!=2 and d[i]<mincost:
                mincost=d[i]
                u=i
        if mincost==float("inf"):
            break
        visited[u]=2
        for v in xrange(n):
            if visited[v]!=2:
                if d[u]+m[u][v]<d[v]:
                    d[v]=d[u]+m[u][v]
                    visited[v]=1
    return d

def main():
    xs,ys,xt,yt=map(int,raw_input().split())
    n=int(raw_input())
    c=[[xs,ys,0]]+[map(int,raw_input().split()) for _ in xrange(n)]+[[xt,yt,0]]
    dist=[[float("inf")]*(n+2) for _ in xrange(n+2)]
    for i in xrange(n+2):
        for j in xrange(n+2):
            if i==j:continue
            dist[i][j]=min(dist[i][j],dist[j][i],max(math.sqrt(abs(c[i][0]-c[j][0])**2+abs(c[i][1]-c[j][1])**2)-c[i][2]-c[j][2],0))
            dist[j][i]=dist[i][j]
    ans=dijkstra(0,dist,n+2)
    print(ans[n+1])
main()
