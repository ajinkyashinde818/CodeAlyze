from math import sqrt
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
def hoge(c):
    return int((-1+sqrt(1+8*c))/2)
n = int(input())
a = prime_factorize(n)
b = set(a)
print(sum([hoge(a.count(e)) for e in b]))
