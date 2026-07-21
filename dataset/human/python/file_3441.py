import numpy as np
import math
import collections
import bisect
from decimal import *


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
    return collections.Counter(a)


N = int(input())
ruisekiwa = [0]
for i in range(1, 50):
    ruisekiwa.append(i + ruisekiwa[i - 1])
PF = prime_factorize(N)

ans = 0
for v in PF.values():
    ans += bisect.bisect_right(ruisekiwa, v) - 1

print(ans)
