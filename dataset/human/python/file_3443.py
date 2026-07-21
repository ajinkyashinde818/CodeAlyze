N = int(input())
if N==1:
    print(0)
    exit()

from collections import Counter
def factorize(n):
    d = Counter()
    m = 2
    while m*m <= n:
        while n%m == 0:
            n //= m
            d[m] += 1
        m += 1
    if n > 1:
        d[n] += 1
    return d

fac = factorize(N)
if len(fac)==1 and N in fac:
    print(1)
    exit()

ans = 0
for v in fac.values():
    n = 1
    while v >= n:
        v -= n
        ans += 1
        n += 1
print(ans)
