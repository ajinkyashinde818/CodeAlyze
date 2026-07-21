import math

n = int(input())
i = 2
count = 0

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

a = factorization(n) 
a_l = len(a)
#print(a)
ans = 0

for i in range(a_l):
  w = a[i][1]
  w_n = 1
  c_n = 0
  while True:
    if w < w_n:
      break
    else:
      w = w-w_n
      w_n = w_n + 1
      c_n = c_n + 1
  ans = ans + c_n
if n == 1:
  print(0)
else:
  print(ans)
