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


N = int(input())
l = prime_factorize(N)
m = set(l)
l2 = list(m)
ans = 0

for i in range(len(l2)):
    x = l.count(l2[i])
    y = 1
    while x >= y:
        x = x - y
        y += 1
        ans += 1
print(ans)
