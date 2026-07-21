d,g=map(int,input().split())
s=[list(map(int,input().split())) for _ in range(d)]
from itertools import product
ans=10000
for b in product([0,1],repeat=d):
  t=0
  sc=0
  mi=0
  for i in range(d):
    if b[i]:
      t+=s[i][0]
      sc+=(s[i][1]+(i+1)*100*s[i][0])
    else:
      mi=i
  z=-(-max(0,g-sc)//((mi+1)*100))
  if z>s[mi][0]-1:
    continue
  ans=min(ans,t+z)
print(ans)
