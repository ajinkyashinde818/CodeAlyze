xs,ys,xg,yg = map(int, input().split())
n = int(input())
xyr=[list(map(int,input().split())) for i in range(n)]

import math
from collections import defaultdict
link = defaultdict(list)
dist = math.sqrt((xs-xg)**2 + (ys-yg)**2)
link[10000].append([20000,dist])

for i in range(n):
    x,y,r = xyr[i]

    dist = math.sqrt((x-xs)**2 + (y-ys)**2) - r
    dist = max(0,dist)
    link[10000].append([i,dist])

    dist = math.sqrt((x-xg)**2 + (y-yg)**2) - r
    dist = max(0,dist)
    link[i].append([20000,dist])

for i in range(n):
    for j in range(i+1,n):
        x1,y1,r1=xyr[i]
        x2,y2,r2=xyr[j]

        dist = math.sqrt((x1-x2)**2 + (y1-y2)**2) - r1 - r2
        dist = max(0,dist)
        link[i].append([j,dist])
        link[j].append([i,dist])

from heapq import heappush, heappop,heappushpop,heapify
from collections import defaultdict
def dks(g,start):
    visited = set()
    hq = []
    heappush(hq, (0,start))

    cost = defaultdict(lambda: float("inf"))
    while hq:
        shortest, i = heappop(hq)
        if i in visited:
            continue
        visited.add(i)
        cost[i] = shortest
        for j, t in g[i]:
            if j in visited:
                continue
            heappush(hq, (shortest + t, j))
    return cost

res = dks(link,10000)
print(res[20000])
