from collections import Counter
from itertools import accumulate
from bisect import bisect_left
N=int(input())
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
A=prime_factorize(N)
a=list(range(1,11))
b=list(accumulate(a))
ans=0
for i,value in Counter(A).items():
    if value in b:
        ans+=b.index(value)+1
    else:
        ans+=bisect_left(b,value)
print(ans)
