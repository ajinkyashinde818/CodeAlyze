def factorize(n):
  fct=[]
  b,e=2,0
  while b*b<=n:
    while n%b==0:
      n=n//b
      e+=1
    if e>0:
      fct.append(e)
    b,e=b+1,0
  if n>1:
    fct.append(1)
  return fct

n=int(input())
ans=0
for i in factorize(n):
  count=1
  while i>=count:
    ans+=1
    i-=count
    count+=1
print(ans)
