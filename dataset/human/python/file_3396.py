from math import sqrt
from collections import Counter
n = int(input())
if n == 1:
    print(0)
    quit()
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
    a.sort()
    return a
l = prime_factorize(n)
c = Counter(l)
ans = 0
for v in c.values():
    i = 1
    while True:
        s = i*(i+1)//2
        if s <= v <= s+i:
            ans += i
            break
        i += 1
print(ans)
