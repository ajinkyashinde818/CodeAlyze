import sys
from scipy.sparse.csgraph import dijkstra
from scipy.sparse import csr_matrix
from itertools import combinations
from math import hypot
input = sys.stdin.readline
sx,sy,gx,gy = map(int,input().split())
n = int(input())
barrier = [list(map(int,input().split())) for i in range(n)]
evv = [(n,n+1,hypot(gx-sx,gy-sy))]
for i in range(n):
  for x1,y1,k in (sx,sy,n),(gx,gy,n+1):
    b1 = barrier[i]
    x2,y2,r = b1[0],b1[1],b1[2]
    dist = max(hypot(x2-x1,y2-y1)-r,0)
    evv.append((i,k,dist))
for i,j in combinations(range(n),2):
  b1 = barrier[i]
  b2 = barrier[j]
  x1,y1,r1 = b1[0],b1[1],b1[2]
  x2,y2,r2 = b2[0],b2[1],b2[2]
  dist = max(hypot(x2-x1,y2-y1)-(r1+r2),0)
  evv.append((i,j,dist))
v1,v2,edge = zip(*evv)
csr = csr_matrix((edge,(v1,v2)),shape = (n+2,n+2))
print(dijkstra(csr, directed = False,indices = n)[n+1])
