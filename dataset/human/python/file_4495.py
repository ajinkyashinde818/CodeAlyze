import sys
from functools import lru_cache


@lru_cache(maxsize=None)
def solve(n):
    ans = 0
    for i in range(1, 10*10):
        if n - i >= 0:
            ans += 1
            n -= i
        else:
            return(ans)


n = int(input())


if n == 1:
    print(0)
    sys.exit()


pf = {}
m = n
for i in range(2, int(m**0.5)+1):
    while m % i == 0:
        pf[i] = pf.get(i, 0)+1
        m //= i
if m > 1:
    pf[m] = 1

ans = list(pf.values())
ans = sum([solve(x) for x in ans])

print(ans)
