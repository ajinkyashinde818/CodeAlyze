import itertools

n = int(input())
ans = 0


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


def q(m):
    check = 0
    while m >= check * (check + 1) / 2:
        check += 1
    return check - 1


a = prime_factorize(n)
gr = itertools.groupby(a)
for key, group in gr:
    ans += q(len(list(group)))

print(ans)
