from itertools import product
from math import ceil
D, G = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(D)]

a = [True, False]
ss = product(a, repeat=D)

li = []
for i in ss:
  lii = []
  for itr, val in enumerate(i):
    if val:
      lii.append(itr)
  li.append(lii)

oneD = set([i for i in range(D)])
    
# print(li)

ans = 10**9
for i in li:
  psum = 0
  cnt = 0
  for j in i:
    psum += (j + 1) * pc[j][0] * 100 + pc[j][1]
    cnt += pc[j][0]
  if psum >= G:
    ans = min(ans, cnt)
  else:
    hoge = max(oneD - set(i))
    if pc[hoge][0] >= ceil((G - psum)/((hoge+1)*100)):
      cnt += ceil((G - psum)/((hoge+1)*100))
      ans = min(ans, cnt)
    
print(ans)
