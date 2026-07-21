import collections
import math

n=int(input())

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

c = collections.Counter(prime_factorize(n))
ans=0
for i in c.keys():
    count=0
    z=c[i]
    for i in range(55):
        z-=i
        if z>=0:
            count=i
        else:
            break
    ans+=count
print(ans)
