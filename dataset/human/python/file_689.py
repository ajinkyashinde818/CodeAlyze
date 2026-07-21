import sys
input=sys.stdin.readline

Xs,Ys,Xg,Yg=map(int,input().split())
N=int(input())
L=[]
L.append([Xs,Ys,0])
for i in range(N):
    x,y,r=map(int,input().split())
    L.append([x,y,r])
L.append([Xg,Yg,0])
cost=[[-1 for i in range(N+2)]for j in range(N+2)]
for i in range(N+2):
    for j in range(i,N+2):
        cost[i][j]=max(0,((L[i][0]-L[j][0])**2+(L[i][1]-L[j][1])**2)**0.5-L[i][2]-L[j][2])
        cost[j][i]=cost[i][j]
#print(cost)


def jdijkstra(s,n,w,cost):
    #始点sから各頂点への最短距離
    #n:頂点数,　w:辺の数, cost[u][v] : 辺uvのコスト(存在しないときはinf)
    d = [float("inf")] * n
    used = [False] * n
    d[s] = 0
    
    while True:
        v = -1
        #まだ使われてない頂点の中から最小の距離のものを探す
        for i in range(n):
            if (not used[i]) and (v == -1):
               v = i
            elif (not used[i]) and d[i] < d[v]:
                v = i
        if v == -1:
               break
        used[v] = True
               
        for j in range(n):
               d[j] = min(d[j],d[v]+cost[v][j])
    return d

#print(jdijkstra(0,N+2,(N+2)**2,cost))
ans=jdijkstra(0,N+2,(N+2)**2,cost)
print(ans[-1])
