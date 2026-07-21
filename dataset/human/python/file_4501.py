import sys
input=lambda: sys.stdin.readline().rstrip()
n=int(input())
pf={}
for i in range(2,int(n**0.5)+1):
  while n%i==0:
    pf[i]=pf.get(i,0)+1
    n//=i
if n>1:
  pf[n]=1
ans=0
for p in pf.keys():
  d=pf[p]
  tot=1
  cur=1
  ct=0
  while tot<=d:
    ct+=1
    if tot+cur+1>d:
      break
    else:
      cur+=1
      tot+=cur
  ans+=ct
print(ans)
