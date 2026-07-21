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

n = int(input())
c = collections.Counter(prime_factorize(n))
ans=0
for i in c:
    tmp=1
    while 1:
        c[i]-=tmp
        if c[i]>=0:
            ans+=1
        else:
            break
        if c[i]==0:
            break
        tmp+=1
print(ans)
