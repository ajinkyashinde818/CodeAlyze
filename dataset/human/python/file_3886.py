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
a = prime_factorize(n)
#print(a)
c = collections.Counter(a)
#print(c)
ans = 0
for v in c.values():
    x = 1
    while True:
        v -=x
        x += 1
        if (v<x):
            ans += (x-1)
            break
print(ans)
