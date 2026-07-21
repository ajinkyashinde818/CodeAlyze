import numpy as np
n = int(input())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(n**0.5)+1):
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
  
fact = factorization(n)
vals = []
for f in fact:
  for e in range(1, f[1]+1):
    vals.append(f[0]**e)
vals.sort()
if n==1:
  print(0)
else:
  ans = 0
  for d in vals:
    if n%d == 0:
      ans += 1
      n /= d
  print(ans)
