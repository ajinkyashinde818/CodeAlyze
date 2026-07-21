import math

d,g = map(int,input().split())

l = [list(map(int,input().split())) for i in range(d)]
ans = float("inf")

for bit in range(1<<d):
  sum = 0
  count = 0
  f = set(range(1,d+1))
  
  for i in range(d):
    if bit & (1<<i):
      sum += (i+1)*l[i][0]*100 + l[i][1]
      count += l[i][0]
      f.discard(i+1)
      
  if sum < g:
    x = max(f)
    n = min(l[x-1][0], math.ceil((g-sum)/(x*100)))
    sum += n*100*x
    count += n
    
  if sum >= g:
    ans = min(ans,count)
    
print(ans)
