import collections
import itertools
r,g,b,n=map(int,input().split())
x,y=n//r,n//g
x,y=list(range(0,r*x+1,r)),list(range(0,g*y+1,g))
l=[i+j for i,j in itertools.product(x,y) if i+j<=n]
z=collections.Counter(l)
count=0
for key,value in zip(z.keys(),z.values()):
  v=n-key
  if v==0:
    count+=value
  elif v%b==0:
    count+=value
print(count)
