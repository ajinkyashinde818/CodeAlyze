import math
def factorization(N):
  tmp=N
  F=[]
  for i in range(2,int(math.sqrt(N))+1):
    if tmp%i==0:
      F.append(i)
      tmp//=i
    while tmp%i==0:
      tmp//=i
    if i>tmp:
      break
  if tmp!=1:
    F.append(tmp)
  return F

N=int(input())
F=factorization(N)
ans=0
for f in F:
  ff=f
  while N%ff==0:
    ans+=1
    N//=ff
    ff*=f
print(ans)
