import collections
N = int(input())

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

c = collections.Counter(prime_factorize(N))
kiso = [1]
for i in range(2, 10):
    kiso.append(kiso[i-2]+i)
d = dict()
k = 1
for i in range(1, 46):
    if i in kiso and i != 1:
        k += 1
    d[i] = k

ans = 0
for n in c:
    ans += d[c[n]]

print(ans)
