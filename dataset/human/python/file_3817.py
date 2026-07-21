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

import collections

a=int(input())
cc=collections.Counter(prime_factorize(a))
cc=cc.values()
ans=0
for k in cc:
    j=1
    while k>=0:
        k=k-j
        ans+=1
        j+=1
    ans=ans-1
print(ans)
