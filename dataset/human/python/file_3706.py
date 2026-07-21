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

c = collections.Counter(prime_factorize(int(input())))
ans = 0
for k in c.keys():
    d = c[k]
    m =1
    while d>0:
        d -= m
        if d <= m:
            ans += m
            break
        m += 1
print(ans)
