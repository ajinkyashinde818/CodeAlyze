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

def inc(n):
  ans = 0
  i = 1
  while True:
    if n - i >= 0:
      n -= i
      i += 1
      ans += 1
    else:
      break
  return ans

import collections

n = int(input())

c = collections.Counter(prime_factorize(n))

num = c.values()

ans = 0

for i in num:
  ans += inc(i)

print(ans)
