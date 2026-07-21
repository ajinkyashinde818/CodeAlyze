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
ans = 0


for l in c.items():
    x = l[1]
    y = 1
    z = 0
    for i in range(1,x+1):
        z += 1 #同じ数のカウンター
        if z > y+1:
            z = 1
            y += 1
    ans += y

print(ans)
