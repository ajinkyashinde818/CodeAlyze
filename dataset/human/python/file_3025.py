import collections

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

c = collections.Counter(prime_factorize(n))

s = 0

def check(x):
    k = 1
    l = 0
    while x >= l + k:
        l += k
        k += 1
    return k-1


for v in c.values():
    s += check(v)



print(s)
