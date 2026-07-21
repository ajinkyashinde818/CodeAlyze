def this (k):
  a=int(pow(1+8*k,0.5))
  return (a-1)//2
from collections import Counter
c=Counter([])
n=int(input())
for i in range(2,int(pow(n,0.5))+1):
  if n%i==0:
    sumi=0
    while n%i==0:
      n=n//i
      sumi+=1
    c[i]=sumi
if n!=1:
  c[n]=1
ans=0
for item in c.values():
  ans+=this(item)
print (ans)
