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


ans = 0
if n > 1:
    tmp = collections.Counter(prime_factorize(n))
    for v in tmp.values():
        i = 1
        while v > 0:
            if v - i >= 0:
                v -= i
                ans += 1
                i += 1
            else:
                break
print(ans)
