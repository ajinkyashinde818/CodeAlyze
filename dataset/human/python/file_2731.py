from itertools import product
D,G = map(int,input().split())
p,c = [0]*D,[0]*D
for i in range(D):
  p[i],c[i] = list(map(int,input().split()))
m = 10*100*10
for a in product([True,False], repeat=D):
  g,n = G,0
  for i in range(D):
    if a[i]:
      n += p[i]
      g -= (c[i]+(i+1)*100*p[i])
  if g <= 0 and n <= m:
    m = n
    continue
  elif m < n:
    continue
  for i in range(D):
    if a[i]:
      continue
    if g > (i+1)*100*(p[i]-1):
      continue
    n += (g+(i+1)*100-1) // ((i+1)*100)
    if n < m:
      m = n
print(m)
