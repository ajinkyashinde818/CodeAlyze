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

l = prime_factorize(n)

import collections
count = collections.Counter(l)

total = 0
for dup in count.items():
    total += 1
    appear = dup[1]
    if appear > 1:
        ite = 1
        accu = 1
        while accu < appear:
            ite += 1
            accu += ite
            if accu > appear:
                continue
            total += 1

print(total)
