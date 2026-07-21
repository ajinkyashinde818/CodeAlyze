import math
from itertools import combinations
d,g = map(int,input().split())
x = []
for i in range(d):
    x1,y1=[int(i) for i in input().split()]
    x.append([x1,y1])
zy = [i for i in range(1,d+1)]
zyu = []
for i in range(d+1):
  zyu.extend(list(combinations(zy, i)))
ans2 = 100000000000000000000000
gou = g+0
for i in zyu:
  ans = 0
  g = gou +0
  for j in i:
    g -= (x[j-1][0] * j*100 + x[j-1][1])
    ans += x[j-1][0]
  if g >0:
    y = d+0
    while y in i:
      y -= 1
    a = x[y-1][0]
    if g > a*y*100:
      continue
    ans += math.ceil(g/(y*100))
  ans2 = min(ans,ans2)
print(ans2)
