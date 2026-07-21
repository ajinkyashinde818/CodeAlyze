from heapq import heappush, heappop
from math import sqrt
xs, ys, xt, yt = map(int, raw_input().split())
n = input()
ps = [map(int, raw_input().split()) for i in xrange(n)]
cant = [0]*n
for i in xrange(n):
    x0, y0, r0 = ps[i]
    for j in xrange(n):
        x1, y1, r1 = ps[j]
        if i == j or r0 > r1: continue
        if (x0 - x1)**2 + (y0 - y1)**2 <= (r1 - r0)**2:
            cant[i] = 1
            break

EPS = 1e-10
que = []
dist = [10**18+7]*n
def calc(x0, y0, r0, x1, y1, r1):
    v = (x0 - x1)**2 + (y0 - y1)**2
    if v <= (r0+r1)**2:
        return 0.
    return sqrt(v) - r0 - r1
for i in xrange(n):
    if cant[i]: continue
    x, y, r = ps[i]
    d = dist[i] = calc(xs, ys, 0, x, y, r)
    heappush(que, (d, i))
while que:
    d, v = heappop(que)
    if dist[v] < d:
        continue
    x0, y0, r0 = ps[v]
    for t in xrange(n):
        if v == t or cant[t]: continue
        x1, y1, r1 = ps[t]
        nd = calc(x0, y0, r0, x1, y1, r1)
        if d+nd < dist[t]:
            dist[t] = d+nd
            heappush(que, (d+nd, t))
ans = sqrt((xs - xt)**2 + (ys - yt)**2)
for i in xrange(n):
    if cant[i]: continue
    x, y, r = ps[i]
    d = calc(xt, yt, 0, x, y, r) + dist[i]
    ans = min(ans, d)
print "%.010f" % ans
