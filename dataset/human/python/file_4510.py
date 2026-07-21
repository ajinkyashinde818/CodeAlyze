n = int(input())
import math
from bisect import bisect
ps = {}
for i in range(2,math.ceil(math.sqrt(n))):
  while n % i == 0:
    n //= i
    if i in ps:
      ps[i] += 1
    else:
      ps[i] = 1
  if n == 1:
    break
if n > 1:
  ps[n] = 1

ss = [i*(i+1)//2 for i in range(1,42)]

ans = 0
for p in ps:
  ans += bisect(ss, ps[p])
print(ans)
