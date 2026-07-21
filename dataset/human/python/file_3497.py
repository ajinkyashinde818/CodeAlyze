from math import sqrt
from collections import defaultdict

N = int(input())

def prime_factorize(n):
    a = defaultdict(int)
    while n % 2 == 0:
        a[2] += 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a[f] += 1
            n //= f
        else:
            f += 2
    if n != 1:
        a[n] += 1
    return a
  
ps = prime_factorize(N)

def func2(k):
  n = 1
  count = 1
  while count * (count+1) // 2 <= k:
    count += 1
  return count-1

res = 0

for value in ps.values():
  if value > 0:
    res += func2(value)

print(res)
