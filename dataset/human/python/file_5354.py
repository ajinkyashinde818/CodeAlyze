import heapq

n,m = map(int,input().split())

roots = [[] for _ in range(n)]

for _ in range(m):
    a,b = map(int,input().split())
    roots[a-1].append(b-1)
    roots[b-1].append(a-1)

def dijkstra(edges, s):
    hq = []
    d = [-1] * n
    d[s] = 0
    heapq.heappush(hq, (0, s))
    while hq:
        d1, p = heapq.heappop(hq)
        for i in edges[p]:
            if d[i] == -1 or d[i] > d1 + 1:
                d[i] = d1 + 1
                heapq.heappush(hq, (d1+1, i))
    return d

d = dijkstra(roots, 0)

if d[-1] == 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
