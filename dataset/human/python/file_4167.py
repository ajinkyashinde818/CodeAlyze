N = int(input())
if N == 1:
    print("0")
    exit()

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

c = collections.Counter(prime_factorize(N))

ans = 0
for i in c.keys():
    num = c[i]
    m = 2
    while num > 0:
        num = num - m
        m += 1
        ans += 1

print(ans)
