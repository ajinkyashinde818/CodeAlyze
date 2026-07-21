from math import hypot
def dijkstra(s,n,cost):
    d=[float("inf")]*n
    used=[False]*n
    d[s]=0
    while True:
        v=-1
        for i in range(n):
            if(not used[i])and v==-1:
               v=i
            elif(not used[i])and d[i]<d[v]:
                v = i
        if v==-1:
            break
        used[v]=True
        for j in range(n):
            d[j]=min(d[j],d[v]+cost[v][j])
    return d
xs,ys,xt,yt,n,*t=map(int,open(0).read().split())
e=[(xs,ys,0)]+list(zip(t[::3],t[1::3],t[2::3]))+[(xt,yt,0)]
cost=tuple([float('inf')]*(n+2)for i in range(n+2))
for i,(x,y,z)in enumerate(e):
    for j,(a,b,c)in enumerate(e):
        cost[i][j]=max(0,hypot(x-a,y-b)-z-c)
print(dijkstra(0,n+2,cost)[-1])
