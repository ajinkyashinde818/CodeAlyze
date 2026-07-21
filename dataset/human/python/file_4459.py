import sys
import collections
N = int(input())
Ans = 0

if N <= 1:
  print(Ans)
  sys.exit()

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

c = collections.Counter(prime_factorize(N))
A = list(c.values())
p = len(A)
#print(A)
#print(p)

Ans = Ans + p
now = 0

for r in range(p):
  now = int(A[r]) - 1
  loop = 2

  for q in range(1000):
    now = now - loop
    if now >= 0:
      Ans = Ans + 1
      loop = loop + 1
    else:
      break

print(Ans)
