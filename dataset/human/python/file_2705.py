import math
d, g = map(int, input().split())
p = []
c = []
su = []
ans = 1000
for i in range(d):
  a,b = map(int, input().split())
  p.append(a)
  c.append(b)
  su.append(a*100*(i+1)+b)
bit = [1,2,4,8,16,32,64,128,256,512]
for i in range(int(math.pow(2,d))):
  count = 0
  score = 0
  for j in range(d):
    if i & bit[j] == 0:
      continue
    score += su[j]
    count += p[j]
  if score < g:
    continue
  for j in range(d):
    if i & bit[j] == 0 or score - su[j] >= g:
      continue
    rest = g - (score - su[j])
    count_tmp = min(count , count - p[j] + math.ceil(rest / ((j+1)*100)))
    ans = min(ans, count_tmp)
print(ans)
