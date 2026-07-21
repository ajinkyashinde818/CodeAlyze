import heapq
INFTY = 10**6
N,M = map(int,input().split())
G = {i:[] for i in range(1,N+1)}
for _ in range(M):
    a,b = map(int,input().split())
    G[a].append(b)
    G[b].append(a)
dist = [INFTY for _ in range(N+1)]
dist[1] = 0
hist = [0 for _ in range(N+1)]
hist[1] = 1
heap = [(0,1)]
while heap:
    d,x = heapq.heappop(heap)
    if dist[x]<d:continue
    hist[x] = 1
    for y in G[x]:
        if hist[y]==0:
            if dist[y]>d+1:
                dist[y] = d+1
                heapq.heappush(heap,(d+1,y))
if dist[N]==2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
