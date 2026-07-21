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

import sys
inp = int(input())
x=prime_factorize(inp)
a=0
xset = set(x)
for i in xset:
  z=x.count(i)
  a+=1
  n=2
  ar=(n*(n+1))/2
  while z>=ar:
    a+=1
    n+=1
    ar=(n*(n+1))/2
print(a)
