import sys
import collections
readline = sys.stdin.readline
 
n = int(readline().strip())
 
a = []
while n % 2 == 0:
  a.append(2)
  n //= 2
f = 3
while f * f <= n:
  if n % f == 0:
    a.append(f)
    n //= f
  else:
    f += 2
if n != 1:
  a.append(n)

if len(a) == 0:
  print(0)
  exit()

c = collections.Counter(a)
p = c.keys()

ans = 0
for i in p:
  v = c[i]
  m = 0
  ans += 1
  for j in range(1,v):
    m += j
    if m + j >= v:
      break
    else:
      ans += 1

print(ans)
