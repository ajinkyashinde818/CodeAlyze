import math
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

def available_n(v):
    value = ((1+8*v)**(1/2) - 1)/2
    return math.floor(value)

n=int(input())
ls = prime_factorize(n)
d={}
for i in ls:
    d.setdefault(i,0)
    d[i]=d[i]+1

count=0
for k,v in d.items():
    count+=available_n(v)

print(count)
