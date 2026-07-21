from itertools import accumulate
from bisect import bisect_right
def prime_factorize_dict(n):
    d = dict()
    while not n & 1:
        d[2] = d.get(2, 0) + 1
        n >>= 1
    f = 3
    while f * f <= n:
        if not n % f:
            d[f] = d.get(f, 0) + 1
            n //= f
        else:
            f += 2
    if n != 1:
        d[n] = d.get(n, 0) + 1
    return d

N = int(input())
l = list(prime_factorize_dict(N).values())
L = list(accumulate(range(10 ** 6)))
print(sum(bisect_right(L, item) - 1 for item in l))
