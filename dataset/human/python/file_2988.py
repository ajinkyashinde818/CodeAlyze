from collections import defaultdict
from functools import lru_cache
from bisect import bisect_right as bir
from collections import Counter
N = int(input())


def prime(n):
    ret = []
    while n % 2 == 0:
        ret.append(2)
        n //= 2

    f = 3
    while f*f <= n:
        if n % f == 0:
            ret.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        ret.append(n)
    return ret


D = Counter(prime(N))

comb = []
m = 0
for i in range(1, 10000):
    m += i
    comb.append(m)


ans = 0
for k, v in D.items():
    ans += bir(comb, v)

print(ans)
