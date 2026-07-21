import collections

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

n = int(input())

c = collections.Counter(prime_factorize(n))

l = len(list(c.keys()))
it = list(c.values())

ans = 0

#print(it)

for i in range(l):
    p = 1
    while (it[i] - p >= 0):
        it[i] -= p
        ans += 1
        p += 1
print(ans)
