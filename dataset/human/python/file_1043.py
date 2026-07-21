import sys
mod=1000000007
n=int(input())
s=str(input())
ans=1
for i in range(1,n+1):
  i=i%mod
  ans=ans*i
  ans=ans%mod
d={"B":1,"W":0}
sg=[]
now=1
sss=0
for i in range(2*n):
  if d[s[i]]==now%2:
    sss+=1
    now+=1
    a="S"
  else:
    a="G"
    now-=1
    if sss>=0:
      ans*=sss
      ans=ans%mod
      sss-=1
    else:
      ans=0
  #print("i",i,a,sss,ans)
if sss==0:
  print(ans)
else:
  print(0)
