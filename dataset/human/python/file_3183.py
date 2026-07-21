from collections import Counter

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

cnt = Counter(prime_factorize(n))
z = []
for k, v in cnt.items():
    for i in range(1, v+1):
        z.append(k**i)
z = list(set(z))
z.sort()

ans = 0
for pe in z:
    if n%pe == 0:
        n /= pe
        ans += 1
print(ans)
