import sys
input = sys.stdin.buffer.readline
from scipy.sparse.csgraph import csgraph_from_dense, dijkstra
def hypot(x1, y1, x2, y2):
  return ((x1-x2)**2 + (y1-y2)**2) ** 0.5
INF = 2**31 - 1
sx, sy, ex, ey = map(int, input().split())
n = int(input())
XYR = [list(map(int, input().split())) for _ in range(n)]
G = [[INF]*(n+2) for _ in range(n+2)]
for i in range(n-1):
  for j in range(i+1, n):
    x1, y1, r1 = XYR[i]
    x2, y2, r2 = XYR[j]
    d = hypot(x1, y1, x2, y2)
    k = max(d-r1-r2, 0)
    G[i][j] = k
for i, xyr in enumerate(XYR):
  x, y, r = xyr
  ds = hypot(sx, sy, x, y)
  de = hypot(ex, ey, x, y)
  ks = max(ds-r, 0)
  ke = max(de-r, 0)
  G[i][n] = ks
  G[i][n+1] = ke
G[n][n+1] = hypot(sx, sy, ex, ey)
C = csgraph_from_dense(G, null_value=INF)
D = dijkstra(C, indices=n, directed=False)
ans = D[n+1]
print(ans)
