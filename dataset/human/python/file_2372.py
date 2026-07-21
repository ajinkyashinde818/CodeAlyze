from itertools import product

D,G=map(int,input().split())
p,c=[],[]

for _ in range(D):
  pi,ci=map(int,input().split())
  p.append(pi)
  c.append(ci)
  
ans=10**4
  
for cpls in product(range(2),repeat=D):
  num=0#回答数
  tensu=0#各cplsの得点
  for i,v in enumerate(cpls,start=1):
    if v==1:
      tensu+=i*100*p[i-1]+c[i-1]
      num+=p[i-1]
  if tensu>=G:
    ans=min(ans,num)
    continue
  for i,v in reversed(list(enumerate(cpls,start=1))):
    if v==0:
      for _ in range(p[i-1]-1):
        tensu+=100*i
        num+=1
        if tensu>=G:
          ans=min(ans,num)
          break
print(ans)
