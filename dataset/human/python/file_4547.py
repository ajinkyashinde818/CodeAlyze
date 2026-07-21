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
a = prime_factorize(n)
from collections import Counter
c = Counter(a)
x = set()
ans = 0
import itertools
r = list(itertools.accumulate(list(range(1,10**5))))
from bisect import bisect
for i in c:
    if c[i]==1:
        ans += 1
    else:
        ind = bisect(r,c[i])
        ans += ind


print(ans)
