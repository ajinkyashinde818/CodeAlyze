import collections
import math

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

a = collections.Counter(prime_factorize(n))

res = 0

for i in a.items():
    if i[1] > 3:
        x = 2
        y = 3
        while True:
            x += 1
            y = y + x
            if y > i[1]:
                res += x - 1
                break
    elif i[1] == 3:
        res += 2
    else:
        res += 1

print(res)
