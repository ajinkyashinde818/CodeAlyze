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


import collections

N = int(input())
c = collections.Counter(prime_factorize(N))
ans = 0

for p, n in c.items():
    for i in range(1, 10000000):
        if n < i:
            break
        ans += 1
        n -= i

print(ans)
