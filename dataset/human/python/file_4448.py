from math import sqrt
from collections import Counter


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


def num_z(n):
    return int((sqrt(1 + 8 * n) - 1) / 2)

################################################################

N = int(input())
factors = Counter(prime_factorize(N))
ans = 0
for n in factors.values():
    ans += num_z(n)
print(ans)
