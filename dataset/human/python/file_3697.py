def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n = n // 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n = n // f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

from collections import Counter

N = int(input())
c = Counter(prime_factorize(N))

ans = 0

v = list(c.values())
l = len(v)
for i in range(l):
    for j in range(40):
        if j*(j+1)//2 <= v[i] and v[i] < (j+1)*(j+2)//2:
            ans = ans + j

print(ans)
