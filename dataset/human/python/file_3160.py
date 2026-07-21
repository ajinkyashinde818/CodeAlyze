from collections import Counter


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


pf = prime_factorize(int(input()))
c = Counter(pf)
#print(c)
ans = 0
for a, b in c.items():
    tmp = 1
    while True:
        b -= tmp
        if b < 0:
            break
        tmp += 1
        ans += 1
print(ans)
