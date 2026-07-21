from collections import Counter

n = int(input())

def factorize(n):
    b = 2
    factor = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            factor.append(b)
        b += 1
    if n > 1:
        factor.append(n)
    return factor

f = factorize(n)
c = Counter(f)

a = 0
for v in c.values():
    i = 1
    while v >= i:
        v -= i
        i += 1
        a += 1

print(a)
