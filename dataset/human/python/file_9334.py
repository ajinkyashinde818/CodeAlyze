n,m=map(int,input().split())
l=list(map(int,input().split()))
from collections import deque
d=deque([0])
li=[0]*n
c=1
lis=[]
for i in range(n+1):
  now=d.pop()
  ne=l[now]
  li[now]=c
  lis.append(now)
  if li[ne-1]!=0:
    z=ne-1
    break
  else:
    d.append(ne-1)
x=lis.index(z)
if m<x+1:
  print(lis[m]+1)
else:
  print(lis[(m-x)%(len(lis)-x)+x]+1)
