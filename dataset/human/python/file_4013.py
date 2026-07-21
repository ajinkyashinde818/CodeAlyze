import collections
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

def cnt(n,c):
    ans=0
    a=1
    for i in c.keys():
        b=1
        while c[i]-b>=0:
            ans+=1
            c[i]-=b
            b+=1
    return ans

print(cnt(n,c))
