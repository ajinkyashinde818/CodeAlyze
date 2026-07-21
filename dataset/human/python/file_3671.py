import collections

m = int(input())

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

c = collections.Counter(prime_factorize(m))
# index = list(c.keys())
number = list(c.values())
ans = 0
for i in number:
    step = 1
    key = 1
    while key <= i:
        ans += 1
        step += 1
        key += step

print(ans)
