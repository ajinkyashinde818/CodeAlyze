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
    
ans=0
n=int(input())
if n==1:
    print(0)
    exit()

cnt=collections.Counter(prime_factorize(n))
for num in cnt.values():
    if num<3:
        ans+=1
    elif num<6:
       ans+=2
    elif num<10:
        ans+=3
    elif num<15:
        ans+=4
    elif num<21:
        ans+=5
    elif num<28:
        ans+=6
    elif num<36:
        ans+=7
    elif num<45:
        ans+=8
    else:
        num+=9
print(ans)
