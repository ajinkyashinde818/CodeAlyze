from collections import Counter


def factorize(n):
    a = 2
    fct = []
    while a * a <= n:
        while n % a == 0:
            n //= a
            fct.append(a)
        a += 1
    if n > 1:
        fct.append(n)
    return fct


n = int(input())
c = Counter(factorize(n))
ans = 0
for v in c.values():
    t = 1
    while v >= t:
        v -= t
        t += 1
        ans += 1
print(ans)
