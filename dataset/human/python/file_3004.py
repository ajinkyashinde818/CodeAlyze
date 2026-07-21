n=int(input())
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
import collections
c = collections.Counter(prime_factorize(n))
ans=0
for x in list(c.values()):
  now=1
  i=1
  while now<x+1:
    now+=(i+1)
    i+=1
  ans+=(i-1)
print(ans)
