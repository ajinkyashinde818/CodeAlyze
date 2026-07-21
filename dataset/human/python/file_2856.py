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

prime = collections.Counter(prime_factorize(n))

ans = 0
for cnt in prime.values():
    c = 0
    while cnt - c > 0:
        c += 1
        cnt -= c
    ans += c

print(ans)
