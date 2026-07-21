def examC():
    N, x  = LI()
    A = LI()
    ans = 0
    cur = A[0]
    if A[0]>x:
        ans += A[0]-x
        cur = x
    for i in range(1,N):
        if cur+A[i]<=x:
            cur = A[i]
            continue
        ans += cur+A[i]-x
        cur = A[i]-(cur+A[i]-x)
    print(ans)
    return

def examD():
    S = SI()
    return

def dijkstra(edge_adj, node, start):
    # graph[node] = [(cost, to)]
    dist = [inf] * node
    used = [False] * node
    dist[start] = 0
    while True:
        v = -1
        for i in range(node):
            if not used[i] and (v == -1 or dist[v] > dist[i]):
                v = i
        if v == -1:
            break
        used[v] = True
        for i in range(node):
            if dist[i] > dist[v] + edge_adj[v][i]:
                dist[i] = dist[v] + edge_adj[v][i]

    return dist
def examE():
    xs,ys,xg,yg = LI()
    N = I()
    XYR = [[]for _ in range(N)]
    for i in range(N):
        XYR[i] = LI()
    XYR.append([xs,ys,0])
    XYR.append([xg,yg,0])
    V = [[0]*(N+2) for _ in range(N+2)]
    for i in range(N+2):
        for j in range(i+1,N+2):
            s = XYR[i]; t = XYR[j]
            cur = ((s[0]-t[0])**2 + (s[1]-t[1])**2)**0.5 - (s[2]+t[2])
            V[i][j] = max(0,cur)
            V[j][i] = max(0,cur)
    D = dijkstra(V,N+2,N)
#    print(D)
    ans = D[-1]
    print(ans)
    return

import sys,copy,bisect,itertools,heapq,math
from heapq import heappop,heappush,heapify
from collections import Counter,defaultdict,deque
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LSI(): return list(map(str,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def SI(): return sys.stdin.readline().strip()
global mod,inf
mod = 10**9 + 7
inf = 10**18

if __name__ == '__main__':
    examE()
