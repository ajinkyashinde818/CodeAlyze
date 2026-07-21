import math
def factorization(n):
  arr=[]
  temp=n
  for i in range(2,int(math.sqrt(n))):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp//=i
      arr.append([i,cnt])
  if temp!=1:
    arr.append([temp,1])
  if arr==[]:
    arr.append([n,1])
  return arr

n=int(input())
if n==1:
  print(0)
  exit()
ans=0
for i in factorization(n):
  if i[1]>=3:
    cnt=1
    while i[1]-cnt>cnt:
      ans+=1
      i[1]-=cnt
      cnt+=1
    if i[1]!=0:
      ans+=1
  else:
    ans+=1
print(ans)
