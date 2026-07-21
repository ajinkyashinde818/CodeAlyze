def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n //= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

N = int(input())
from collections import Counter
c = Counter(prime_decomposition(N))
ans = 0
for i in c:
    k = 1
    while(c[i]-k>=0):
        if c[i]>0:
           c[i] -= k
           ans += 1
           k += 1
print(ans)
