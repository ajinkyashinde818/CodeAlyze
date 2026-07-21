from collections import Counter
import math

N = int(input())
def prime_factors(n):
    """Returns all the prime factors of a positive integer"""
    factors = []
    d = 2
    while n > 1:
        while n % d == 0:
            factors.append(d)
            n /= d
        d = d + 1
        if d*d > n:
            if n > 1: factors.append(int(n))
            break
    return factors


def count_moves(exponents):
    num = 0
    for ex in exponents:
        num += math.floor(0.5*(math.sqrt(8*ex+1) - 1))

    return num


pf = prime_factors(N)
pf = Counter(pf)
exponents = list(pf.values())
ans = count_moves(exponents)

print(ans)
