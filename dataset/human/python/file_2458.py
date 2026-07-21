from itertools import product as p

d,g=map(int,input().split())
l=[(0,0) for _ in range(d)]
for i in range(d):
  l[i]=tuple(map(int,input().split()))
f=lambda x:[i for (i,j) in enumerate(x) if j==0]
res={}

for i in p([0,1],repeat=d):
  b=f(i)
  cnt=0
  t_val=0

  for (j,k) in enumerate(i):
      if k:
        t_val+=((j+1)*100*l[j][0]+l[j][1])
        cnt+=(l[j][0])
  
  if b:
    inc=max(b)
    pl=g-t_val
    c_inc=0
    if pl>0:
      if pl%((inc+1)*100):
        c_inc=1+pl//((inc+1)*100)
      else:
        c_inc=pl//((inc+1)*100)
      if c_inc<l[inc][0]:
        t_val+=(c_inc*(inc+1)*100)
        cnt+=(c_inc)
      else:
        t_val+=((l[inc][0]-1)*(inc+1)*100)
        cnt+=(l[inc][0]-1)
  res[i]=(t_val,cnt)

o=sorted([i for i in res.values() if i[0]>=g],key=lambda x:x[1])
print(o[0][1])
