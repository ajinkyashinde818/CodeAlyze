n = int(input())
ans = 0
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
from collections import Counter
c = Counter(prime_factorize(n))
for i in c.values():
    for j in range(1,50):
        if j*(j+1)/2 <= i < (j+1)*(j+2)/2:
            ans += j
            break
print(ans)
