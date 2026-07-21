import math

d,g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]
ans = 10 ** 18
for i in range(2 ** d):
  solve = []
  tmp = 0
  score = 0
  for j in range(d):
    solve.append((i >> j) & 1)
  for j in range(d):
    if not solve[j]:
       continue
    p,c = pc[j]
    tmp += p
    score += p * (j+1) * 100 + c
  if score >= g:
    ans = min(ans, tmp)
    continue
  res = g - score
  for j in range(d-1,-1,-1):
    if not solve[j]:
      point = (j+1) * 100
      p,c = pc[j]
      must = math.ceil(res / point)
      if must <= p:
        tmp += must
        ans = min(ans, tmp)
      break
print(ans)
