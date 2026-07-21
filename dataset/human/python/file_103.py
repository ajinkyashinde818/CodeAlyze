r,g,b,n=map(int,input().split())
def INT(m):
  if int(m)==m:
    return True
  return False
aa=[r,g,b]
aa.sort()
a,b,c=aa[0],aa[1],aa[2]
ans=0
for i in range(n//c +1):
  for j in range((n-i*c)//b +1):
    if INT((n-i*c-j*b)/a):
      ans+=1
print(ans)
