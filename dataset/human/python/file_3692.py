from collections import Counter


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


n = int(input())
pf = prime_factorize(n)
c = Counter(pf)

ans = 0
for v in c.values():
    i = 1
    while v > 0:
        v -= i
        i += 1
        if v >= 0:
            ans += 1

print(ans)
