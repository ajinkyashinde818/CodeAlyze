import math,heapq,sys
input = sys.stdin.readline
xs,ys,xe,ye = map(int,input().split())
cs = [(xs,ys,0), (xe,ye,0)]
N = int(input())
for i in range(N):
    cs.append(tuple(map(int,input().split())))

def calc_cost(i,j):
    if i == j: return float('inf')
    x1,y1,r1 = cs[i]
    x2,y2,r2 = cs[j]
    cost = max(0, math.hypot(x1-x2,y1-y2) - r1 - r2)
    return cost

INF = float('inf')
direct = calc_cost(0,1)
hq = []
for i in range(1,N+2):
    c = calc_cost(0,i)
    if c > direct: continue
    hq.append((c,i))
heapq.heapify(hq)
not_visited = set(range(1,N+2))
cost = [0] + [INF] * (N+1)
while hq:
    c,v = heapq.heappop(hq)
    if v not in not_visited: continue
    if v == 1:
        print(c)
        exit()
    cost[v] = c
    not_visited.remove(v)
    for to in not_visited:
        newcost = calc_cost(v, to)
        if cost[to] <= cost[v] + newcost: continue
        if direct < cost[v] + newcost: continue
        heapq.heappush(hq, (cost[v] + newcost, to))
