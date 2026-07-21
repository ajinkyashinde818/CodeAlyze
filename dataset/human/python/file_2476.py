import math
a,b=map(int,input().split())
c=[list(map(int,input().split())) for i in range(a)]
d=[0 for i in range(a)]
for i in range(a):
  d[i]=(c[i][0]*(i+1)*100+c[i][1])
e=[0 for i in range(a)]
f=100000000
def s(e,d,c,i):
  g=0
  h=0
  e[i]=c[i][0]
  for j in range(a):
    if e[j]!=0:
      g+=d[j]
    if e[j]==0:
      h=j
  gh=c[h][0]
  global b
  global f
  if b<=g:
    f=min(f,sum(e))
  elif b<=g+(h+1)*100*(gh-1):
    hh=math.ceil((b-g)/((h+1)*100))
    f=min(f,sum(e)+hh)
  if i!=a-1:
    s(e,d,c,i+1)
  g=0
  h=0
  e[i]=0
  for j in range(a):
    if e[j]!=0:
      g+=d[j]
    if e[j]==0:
      h=j
  gh=c[h][0]
  global b
  global f
  if b<=g:
    f=min(f,sum(e))
  elif b<=g+(h+1)*100*(gh-1):
    hh=math.ceil((b-g)/((h+1)*100))
    f=min(f,sum(e)+hh)
  if i==a-1:
    return
  else:
    s(e,d,c,i+1)

s(e,d,c,0)
print(f)
