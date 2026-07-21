import math

d, g = map(int, input().split())
p = [0]*d
c = [0]*d

for i in range(d):
  p[i], c[i] = map(int, input().split())

point =[i*100 for i in range(1, d+1)]
ans = float("inf")

for i in range(1<<d):
  score = 0
  cnt = 0
  for j in range(d):
    if i>>j &1:
      cnt += p[j]
      score += point[j]*p[j] + c[j]
  if score >= g:
    ans = min(ans, cnt)
    continue
  for j in range(d)[::-1]:
    if i >> j &1:
      continue
    x = min(math.ceil((g-score)/point[j]), p[j]-1)
    cnt += x
    score += point[j]*x
    if score >= g:
      ans =min(ans, cnt)
      break
print(ans)
