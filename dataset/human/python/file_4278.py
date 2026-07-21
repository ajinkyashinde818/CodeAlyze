import collections
n=int(input())
if n==1:
  print(0)
  exit()
b=int(n**0.5)
i=2
l=[]
while i<=b:
  if n%i==0:
    l.append(i)
    n=n//i
  else:
    i+=1
if n>b:
  l.append(n)
c=collections.Counter(l)
v=list(c.values())

ans=0
for vv in v:
  wa=1
  s=1
  while True:
    if vv<wa:
      break
    s+=1
    wa+=s
  ans+=(s-1)
print(ans)
