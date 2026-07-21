import collections
n=int(input())
ans=0
d=1
m=0
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

c=collections.Counter(prime_factorize(n))
for i in range(len(list(c.values()))):
    while d*(d+1)/2<list(c.values())[i]+1:
        if m<=d:
            m=d
            d+=1
    if d*(d+1)/2>=list(c.values())[i]+1:
        ans+=m
        d=1
        m=0
print(ans)
