from heapq import heappop,heappush
N,M = map(int,input().split())
T = [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    T[a].append(b)
    T[b].append(a)
D = [5]*(N+1)
Q = [(0,1)]
while Q:
    cost,v = heappop(Q)
    if cost>2 or cost>=D[v]:continue
    D[v] = cost
    for c in T[v]:
        heappush(Q, (cost+1, c))
print("POSSIBLE" if D[N]<=2 else "IMPOSSIBLE")
