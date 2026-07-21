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
n=int(input())
p=collections.Counter(prime_factorize(n))
p=p.values()

ans=0
for i in p:
    k=1
    while True:
        if i-k>=0:
            i-=k
            ans+=1
            k+=1
        else:
            break

print(ans)
