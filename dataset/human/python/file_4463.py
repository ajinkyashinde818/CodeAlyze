from sys import stdin
import collections

def prime_factorize(n):
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
    return a

N = int(stdin.readline().rstrip())
res = 0
if N>=2:
  c = collections.Counter(prime_factorize(N))
  for v in c.values():
    for n in range(1,10):
      if v < n:
        break
      else:
        v -= n
        res += 1
print(res)
