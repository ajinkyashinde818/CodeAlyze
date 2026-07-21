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
A = list(c.values())

def dg(x):
    x = int(x)
    y = ((x * 8 + 1) ** (1 / 2) - 1) // 2
    return y

ans = 0
for v in A:
    ans += int(dg(v))

print(ans)
