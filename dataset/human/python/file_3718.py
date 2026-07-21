n = int(input())

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

P = prime_factorize(n)

import collections
C = collections.Counter(P)


L = [0]
for i in range(1, 1000):
    L.append(L[-1] + i)

import bisect


ans = 0

for k, v in C.items():
    i = bisect.bisect(L, v) - 1
    ans += i
print(ans)
