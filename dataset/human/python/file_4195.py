from collections import Counter

N = int(input())

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
c = Counter(prime_factorize(N))
n = 0
for i, v in c.items():
    t = 1
    a = 2
    while t <= v:
        n += 1
        t += a
        a += 1
print(n)
