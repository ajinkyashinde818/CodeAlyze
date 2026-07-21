import math
def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp //= i
      arr.append(cnt)
  if temp!=1:
    arr.append(1)
  if arr==[]:
    arr.append(1)
  return arr
n = int(input())
if n== 1:
  print(0)
  exit()
x = factorization(n)
c = 0
for xi in x:
  s = 0
  i = 1
  while True:
    if s+i <=xi:
      s += i
      c += 1
    else:
      break
    i += 1    
print(c)
