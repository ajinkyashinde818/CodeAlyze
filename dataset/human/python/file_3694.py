def cultimes(x):
  base=0
  start=0
  if x==0:
    return 0
  if x==1:
    return 1
  while  start <x+1:
    base+=1
    start=(base+1)*(base+2)//2
  return base
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
n=int(input())
m=factorization(n)
t=0
for x in m:
  t+=cultimes(x[1])
t=int(t)
if n==1:
  t=0
print(t)
