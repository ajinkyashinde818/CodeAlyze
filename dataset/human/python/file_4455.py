n=int(input())
def prime_factorize(n):
    a=[]
    while n%2==0:
        a.append(2)
        n//=2
    f=3
    while f**2<=n:
        if n%f==0:
            a.append(f)
            n//=f
        else:
            f+=2
    if n!=1:
        a.append(n)
    return(a)
import collections
A=collections.Counter(prime_factorize(n))
ans=0
import math
for v in A.values():
    x=math.floor(v**0.5)
    while x*(x+1)<=v*2:
        x+=1
    ans+=x-1
print(ans)
