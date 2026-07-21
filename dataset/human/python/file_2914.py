N = int(input())
import math
n = int(math.sqrt(N)) + 1
p = []
for i in range(2,n):
  if N % i == 0:
    a = 0
    while N % i == 0:
      N //= i
      a += 1
    p.append([i,a])
if N != 1:
  p.append([N,1])
ans = 0
l = len(p)
for i in range(l):
  a = p[i][1]
  j = 1
  while a-j >= 0:
    a -= j
    j += 1
    ans += 1
print(ans)
