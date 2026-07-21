from math import ceil
d,g = map(int,input().split())
point = [list(map(int,input().split())) for _ in range(d)]
ans = 10**18
for i in range(2**d):
  l = []
  cnt = 0
  s = 0
  for j in range(d):
    if i >> j & 1:
      cnt += point[j][0]
      s += point[j][0]*100*(j+1) + point[j][1]
    else:
      l.append(j)
  if s >= g:
    ans = min(ans,cnt)
    continue
  for j in l:
    if g-s > 100*(j+1)*(point[j][0]-1):
      continue
    else:
      ans = min(ans,cnt+ceil((g-s)/(100*(j+1))))
print(ans)
