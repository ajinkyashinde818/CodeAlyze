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


N = int(input())
c = collections.Counter(prime_factorize(N))
c = list(c.items())
ans = 0
for i in range(len(c)):
    d= c[i][1]
    t=1
    while d>0:
        d -= t
        t += 1
        if d>=0:
            ans +=1

print(ans)
