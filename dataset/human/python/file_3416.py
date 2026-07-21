from collections import defaultdict, Counter
from fractions import Fraction
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

N = int(input())
if N == 1:
    print(0)
    exit()
result = Counter(prime_factorize(N))

count = 0
for key in result.keys():
    v = result[key]
    i = 1
    while(v >= i):
        v -= i
        count += 1
        i += 1
print(count)
