import sys

n = int(input())

if n == 1:
    print(0)
    sys.exit()

import collections
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

c = collections.Counter(prime_factorize(n))
v = list(c.values())

count= 0
for e in v:
    for i in range(1,40):

        e -= i
        if e >= 0:
            count += 1
        else:
            break

print(count)
