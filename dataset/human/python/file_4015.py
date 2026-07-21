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
import collections
import math
lst = prime_factorize(N)
c = collections.Counter(lst)
count = 0
for _, n in c.items():
    x = (-1+math.sqrt(1+8*n))//2
    count += x
print(int(count))
