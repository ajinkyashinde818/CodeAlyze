N = int(input())
from collections import Counter
from itertools import accumulate
from bisect import bisect_right
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
cum_lis = list(accumulate([i for i in range(1000)]))
c = Counter(prime_factorize(N))
ans = 0
for num in c.values():
    ans += bisect_right(cum_lis, num)-1
print(ans)
