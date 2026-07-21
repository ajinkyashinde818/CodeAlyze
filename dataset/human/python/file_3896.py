from collections import defaultdict


def prime_factorize(n):
    ret = defaultdict(int)
    while n % 2 == 0:
        n //= 2
        ret[2] += 1
    d = 3
    while d * d <= n:
        while n % d == 0:
            n //= d
            ret[d] += 1
        d += 2
    if n > 1:
        ret[n] += 1
    return dict(ret)


n = int(input())
pf = prime_factorize(n)
ans = 0
for c in pf.values():
    i = 1
    while i <= c:
        c -= i
        i += 1
        ans += 1
print(ans)
