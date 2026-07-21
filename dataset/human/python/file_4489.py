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

import collections
c = collections.Counter(prime_factorize(n))

ret = 0
for k, num in c.items():
    cnt = 1
    while True:
        num -= cnt
        if num >= 0:
            ret += 1
        else:
            break
        cnt += 1

print(ret)
