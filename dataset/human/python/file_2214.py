import itertools
import math
d,g=map(int,input().split())
x=[list(map(int,input().split())) for i in range(d)]
y=[]
z=[x[i][0]-1 for i in range(d)]
zz=[]
ans=10**10

pin=0
for i in range(d):
  pin+=100
  y.append(x[i][0]*pin+x[i][1])
  zz+=[pin]

for lst in itertools.product(range(2),repeat=d):
  sum=0
  cnt=0
  for i in range(d):
    if lst[i]==1:
      cnt+=x[i][0]
      sum+=y[i]
  if sum>=g:
      ans=min(ans,cnt)
  else:
    lack=g-sum
    for j in range(d-1,-1,-1):
      if lst[j]==0:  
        if z[j]*zz[j]>=lack:
            cnt+=math.ceil(lack/zz[j])
            ans=min(ans,cnt)         
            break
        else:
            cnt+=z[j]
            lack-=z[j]*zz[j]
    

print(ans)
