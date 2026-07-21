import collections as ct

n = int(input())

def calc(x):
    num = 1
    ref = 0

    while num <= x:
        x -= num
        ref += 1
        num += 1
    
    return ref

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

c = ct.Counter(prime_factorize(n))
d = list(c.values())
ans = list(map(calc,d))

print(sum(ans))
