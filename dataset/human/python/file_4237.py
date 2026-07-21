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

d = []
for i in range(1, 40):
    for j in range(i+1):
        d.append(i)

lis = prime_factorize(n)
lis_s = set(lis)
ans = 0
for el in lis_s:
    ans += d[lis.count(el) - 1]
print(ans)
