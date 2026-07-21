n=int(input())
ans=0
i=0
if n%2==0:
  while n%2==0:
    i+=1
    n//=2
def judge(n):
  s=0
  i=0
  while s<=n:
    i+=1
    s=i*(i+1)//2
  return i-1
ans+=judge(i)
for i in range(3,int(n**0.5),2):
  if n%i==0:
    cnt=0
    while n%i==0:
      n//=i
      cnt+=1
    ans+=judge(cnt)
if n!=1:
  ans+=1
print(ans)
