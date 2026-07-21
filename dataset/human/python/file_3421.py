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

b = int(input())
c = collections.Counter(prime_factorize(b))
ans = 0

for i in (c.keys()) :
    for j in range (50) :
        if j*(j+1)/2 <= c[i] < (j+1)*(j+2)/2 :
            ans += j

print(ans)
