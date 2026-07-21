import math
n = int(input())
l = int(math.sqrt(n))
ans = 0
  
insu = []
sisu = []
i = 2
while i <= l:
  if n % i == 0:
    if i in insu:
      sisu[insu.index(i)] += 1
    else:
      insu.append(i)
      sisu.append(1)
    n //= i
  else:
    i += 1
if n != 1:
  insu.append(n)
  sisu.append(1)
  
if not insu:
  if n == 1:
    print(0)
  else:
    print(1)
  exit()

for s in sisu:
  cnt = 1
  while cnt * (cnt + 1) / 2 <= s:
    ans += 1
    cnt += 1
    
# print(insu)
# print(sisu)
print(ans)
