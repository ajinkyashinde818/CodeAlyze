import math
import collections

n = int(input())

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

if n == 1:
    print(0)
    exit()
else:
    c = collections.Counter(prime_factorize(n))

res = 0
for x, y in c.items():
    num = int( (-1 + (1 +8*y)**(0.5))/2 )
    res += num

print(res)
