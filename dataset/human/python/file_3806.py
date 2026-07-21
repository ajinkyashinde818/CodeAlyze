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

import math
import collections
N = int(input())
tmp = prime_factorize(N)
C = collections.Counter(tmp)
S = set()
for k, v in C.items():
    for i in range(v):
        S.add(k**(i+1))
ans = 0
for s in sorted(S):
    if N%s == 0:
        N = N//s
        ans += 1
print(ans)
