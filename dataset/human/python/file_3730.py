import numpy as np
from math import sqrt
from collections import defaultdict


def sieve(x):
    primes = []
    is_prime = np.ones(x + 1, bool)
    is_prime[0] = is_prime[1] = False
    for i in range(x + 1):
        if is_prime[i]:
            primes.append(i)
            is_prime[2*i::i] = False

    return primes


def prime_fact(x):
    mx = int(sqrt(x)) + 5
    primes = sieve(mx)
    pf = defaultdict(int)
    for e in primes:
        while x % e == 0:
            x //= e
            pf[e] += 1

    if x != 1:
        pf[x] += 1

    return pf


n = int(input())

pf = prime_fact(n)
ans = 0
for v in pf.values():
    i = 1
    while (i + 1) * (i + 2) // 2 <= v:
        i += 1

    ans += i

print(ans)
