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

a=collections.Counter(prime_factorize(n)).values()
res=0
for count in a:
    i=1
    while count>=0:
        count-=i
        i+=1
        res+=1
    res-=1
print(res)
