import sys
import math
from collections import defaultdict
from bisect import bisect_left, bisect_right

sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]

mod = 10**9 + 7

def I(): return int(input())
def LI(): return list(map(int, input().split()))
def LIR(row,col):
    if row <= 0:
        return [[] for _ in range(col)]
    elif col == 1:
        return [I() for _ in range(row)]
    else:
        read_all = [LI() for _ in range(row)]
        return map(list, zip(*read_all))

#################

# 各円どうしの距離を持ってダイクストラをする

from heapq import heappop, heappush
def dijkstra(E,s,n):
    d = [float('inf')]*n
    d[s] = 0
    q = []
    heappush(q,(0,s))
    while q:
        du,u = heappop(q)
        if d[u] < du:
            continue
        for v,weight in E[u].items():
            dnew = du + weight
            if d[v] > dnew:
                d[v] = dnew
                heappush(q,(dnew,v))
    return d

# 中心c1,半径r1の円 と 中心c2,半径r2の円 の距離
def dist_two_circles(c1,r1,c2,r2):
    dist2 = (c1[0]-c2[0])**2 + (c1[1]-c2[1])**2
    if dist2 > (r1+r2)**2:
        return dist2**0.5-r1-r2
    else:
        return 0.0

# 点(x0,y0) と 中心c,半径rの円　の距離
def dist_point_circle(x0,y0,c,r):
    dist2 = (c[0]-x0)**2 + (c[1]-y0)**2
    if dist2 > r**2:
        return dist2**0.5-r
    else:
        return 0.0

xs,ys,xt,yt = LI()
N = I()
x,y,r = LIR(N,3)

E = [dict() for _ in range(N+2)]

for i in range(N):
    for j in range(i+1,N):
        ci = (x[i],y[i])
        cj = (x[j],y[j])
        dist = dist_two_circles(ci,r[i],cj,r[j])
        E[i+1][j+1] = dist
        E[j+1][i+1] = dist

for i in range(N):
    ci = (x[i],y[i])
    dist_s = dist_point_circle(xs,ys,ci,r[i])
    E[0][i+1] = dist_s
    dist_t = dist_point_circle(xt,yt,ci,r[i])
    E[i+1][N+1] = dist_t

E[0][N+1] = ((xs-xt)**2 + (ys-yt)**2)**0.5

d = dijkstra(E,0,N+2)
print(d[N+1])
