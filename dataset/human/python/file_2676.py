from itertools import product
from math import ceil
n,k=map(int,input().split())
A=[]
for i in range(1,n+1):
  a,b=map(int,input().split())
  A+=[(a,i*100,a*i*100+b)]

ans=1e9
for p in product([0,1],repeat=n):
  s=0
  c=0
  m=0
  for i,j in enumerate(p):
    if j==1:
      c+=A[i][0]
      s+=A[i][2]
    else:
      m=max(m,i)
  if s>=k:
    ans=min(ans,c)
  else:
    if (k-s)/A[m][1]<A[m][0]:
      ans=min(ans,c+ceil((k-s)/A[m][1]))
print(ans)
