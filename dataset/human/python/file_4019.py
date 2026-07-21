from collections import Counter
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

def cnt(num):
    i=1
    co=0
    while num>=0:
        num-=i
        co+=1
        i+=1
    return co-1

n=int(input())
c=Counter(prime_factorize(n))
l=list(c.values())
r=0
for x in l:
    r+=cnt(x)
print(r)
