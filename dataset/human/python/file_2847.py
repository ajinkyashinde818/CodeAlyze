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
ans = 0
for _,value in c.items():
    i = 0
    while value>i:
        i += 1
        value -= i
    ans += i
print(ans)
