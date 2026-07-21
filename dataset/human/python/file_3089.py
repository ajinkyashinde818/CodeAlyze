import collections
import math
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
n = int(input())
c = collections.Counter(prime_factorize(n))
d = list(c.values())
number = 0
for i in range(len(d)):
    number += math.floor((-1 + math.sqrt(1 + 8*d[i]))/2)
print(number)
