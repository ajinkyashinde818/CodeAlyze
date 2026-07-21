N = int(input())
from collections import Counter
from bisect import bisect
def prime_factorization(n):
    factor = []
    f = 2
    while f ** 2 <= n:
        if n % f == 0:
            factor.append(f)
            n //= f
        else:
            f += 1
    if n > 1:
        factor.append(n)
    return factor

p = prime_factorization(N)
c = Counter(p)

ans = 0
L = [0]
i = 1
while L[-1] < 10**12:
    L.append(i + L[-1])
    i += 1

for a in c.keys():
    b = c[a]
    i = bisect(L, b)
    ans += i-1
print(ans)
