m = int(input())

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





from math import sqrt
def solve(x):
    return int((sqrt(1 + 8 * x) - 1)/2)



count = 0
for i in Counter(prime_factorize(m)).values():
    count += solve(i)
print(count)
