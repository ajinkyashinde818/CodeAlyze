import math
import collections

N = int(input())

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

factors = prime_factorize(N)

c = collections.Counter(factors)

count = 0

for k, v in c.items():
    i = 0
    rem = v
    while True:
        i += 1
        rem -= i
        if rem < 0:
            break
        count += 1

print(count)
