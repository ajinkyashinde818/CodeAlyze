import heapq

xs,ys,xt,yt = map(int, input().split())
N = int(input())
L = [[int(l) for l in input().split()] for _ in range(N)]

def dist(x, y, s, t):
    return ((x-s)**2 + (y-t)**2)**0.5
    
h = []
for i in range(N):
    heapq.heappush(h, (max(0, dist(xs, ys, L[i][0], L[i][1])-L[i][2]), i))

inf = 10**10
d = [inf]*N
cnt = 0
while cnt < N:
    temp = heapq.heappop(h)
    if d[temp[1]] < inf:
        continue
    cnt += 1
    d[temp[1]] = temp[0]
    for i in range(N):
        if d[i] < inf:
            continue
        heapq.heappush(h, (temp[0]+max(0, dist(L[i][0], L[i][1], L[temp[1]][0], L[temp[1]][1])-L[i][2]-L[temp[1]][2]), i))

ans = dist(xs, ys, xt, yt)
for i in range(N):
    ans = min(ans, d[i]+max(0, dist(xt, yt, L[i][0], L[i][1])-L[i][2]))

print(ans)
