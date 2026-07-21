from collections import Counter
from itertools import count


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


def index_counter(e):
    c = 0
    for i in count(start=1):
        e -= i
        if e >= 0:
            c += 1
        else:
            break
    return c


N = int(input())
prime_factors = Counter(prime_factorize(N))
ans = 0
for key, value in prime_factors.items():
    ans += index_counter(value)
print(ans)
