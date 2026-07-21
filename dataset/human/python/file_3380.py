from itertools import groupby
n =int(input())

def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n%i == 0:
      n //= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

from itertools import groupby
ans = 0
p = prime_decomposition(n)
for k,g in groupby(p):
  gn = len(list(g))
  for i in range(1,1000000):
    gn -= i
    if gn >= 0:
      ans += 1
    else:
      break
print(ans)
