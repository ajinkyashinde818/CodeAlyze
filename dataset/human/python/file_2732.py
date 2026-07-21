from itertools import product
from math import ceil

D,G = map(int,input().split())
p = [0] * D
c = [0] * D

for i in range(D):
  p[i], c[i] = map(int,input().split())

ans=1e9
for x in product([0,1],repeat=D):
  cnt = 0
  pnt = 0
  i = 0
  maxi = 0 # 中途半端に解くiを決める。
  incompflg = False
  for y in x:
    if y == 1:
      # 完全回答するパターン
      cnt += p[i]
      pnt += (i+1)*100*p[i] + c[i]
    else:
      # 完全回答しないパターン
      maxi = i
      incompflg = True
    i += 1
  
  if pnt >= G:
    ans = min(ans, cnt)
  elif incompflg and pnt + (p[maxi]-1) * (maxi+1) * 100 >= G:
    ans = min(ans, cnt+ ceil( (G-pnt) / ( (maxi+1) * 100 ) ))
  #print(x, cnt, pnt, ans)
  
print(ans)
