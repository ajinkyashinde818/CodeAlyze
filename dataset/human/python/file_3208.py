import math
N=int(input())
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
def tri(num):
  s=int(math.sqrt(2*num))
  t=s*(s+1)//2
  if t>num:
    return s-1
  else:
    return s

if N==1:
  print(0)
else:
  ls=factorization(N)
  ans=0
  for a,b in ls:
    ans+=tri(b)
  print(ans)
