import math
n = int(input())
if n == 1:
  print(0)
  exit(0)
  
pows = []
upto = int(math.sqrt(n))
for i in range(2, upto+1):
  if n % i == 0:
    cc = 0
    while n % i == 0:
      n //= i
      cc += 1
    pows.append(cc)
    

if n != 1:
  pows.append(1)
    
if len(pows) == 0:
  print(1)
  exit(0)
  
ans = 0
for pp in pows:
  start = 1
  cc = 0
  while pp - start >= 0:
    cc += 1
    pp -= start
    start += 1

  ans += cc

print(ans)
