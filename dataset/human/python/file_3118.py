N=int(input())
if N==1:
  print(0)
  exit(0)
def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp //= i
      arr.append([i, cnt])
  if temp!=1:
    arr.append([temp, 1])
  if arr==[]:
    arr.append([n, 1])
  return arr

X=factorization(N)
ans=0
for p,n in X:
  _n=0
  while n>0:
    _n+=1
    if n-_n<=_n:
      n=0
    else:
      n-=_n
    ans+=1
print(ans)
