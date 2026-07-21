import collections
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

d = collections.Counter(prime_factorize(n))

r = 0
for v in d.values():
    _v = v
    e = 1
    while _v > 0:
        _v -= e
        if _v >= 0:
            r += 1
        e += 1

print(r)
