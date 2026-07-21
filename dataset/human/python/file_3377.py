n = int(input())
if n == 1:
    print(0)
    exit()

from collections import Counter
def factorize(n):    
    d = Counter()
    if n < 2:
        return d
    
    while n%2 == 0:
        n //= 2
        d[2] += 1

    m = 3
    while m*m <= n:
        while n%m == 0:
            n //= m
            d[m] += 1
        m += 2
    if n > 1:
        d[n] += 1
    return d
 
fac = factorize(n)
ans = 0
for v in fac.values():
    n = 1
    while v >= n:
        v -= n
        ans += 1
        n += 1
print(ans)
