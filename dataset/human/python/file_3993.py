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


N = int(input())

c = Counter(prime_factorize(N))
keys = c.keys()
ans = 0

for key in keys:
    cnt = 0
    while c[key] >= cnt + 1:
        ans += 1
        c[key] -= (cnt + 1)
        cnt += 1

print(ans)
