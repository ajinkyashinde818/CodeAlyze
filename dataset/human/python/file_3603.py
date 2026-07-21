n=int(input())

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

c = collections.Counter(prime_factorize(n))
res = 0
for key,value in c.items():
    i = 1
    while value >= i :
        value -= i
        res+=1
        i+=1
print(res)
