import collections
N=int(input())
def prime_factorize(n):
    a = []
    b=[]
    c=[]
    d=[]
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
    for z in a:
        if not z in b:
            b.append(z)
    for z in b:
        c.append(a.count(z))
    for z in range(len(c)):
        for y in range(1,c[z]+1):
            d.append(b[z]**y)
    d=sorted(d)
    number=N
    answer=0
    for z in d:
        if number%z==0:
            number=int(number/z)
            answer+=1
    return answer
if N==1:
    print(0)
else:
    print(prime_factorize(N))
