import math 
N = int(input())

used = []

def primes(n):
  primefac = dict()
  d = 2
  while d * d <= n:
    iter_ = 0
    while n % d == 0:
      iter_ += 1
      n //= d
    primefac[d] = iter_
    d += 1
  if n > 1:
    primefac[n] = 1
  return primefac 

p = primes(N)

count = 0
for (k, v) in p.items():
  count += math.floor(-0.5 + math.sqrt(0.25 + 2 * v))

print(count)
