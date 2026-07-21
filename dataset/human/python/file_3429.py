def primes(n):
    n, correction = n-n%6+6, 2-(n%6>1)
    sieve = [True] * (n//3)
    for i in range(1, int(n**0.5)//3+1):
        if sieve[i]:
            k = 3*i+1|1
            sieve[k*k//3::2*k] = [False] * ((n//6-k*k//6-1)//k+1)
            sieve[k*(k-2*(i&1)+4)//3::2*k] = [False] * ((n//6-k*(k-2*(i&1)+4)//6-1)//k+1)
    return [2, 3] + [3*i+1|1 for i in range(1, n//3-correction) if sieve[i]]
from collections import defaultdict

n=int(input())
primelist=primes(int(n**0.5+1))+[n+1]
factors=defaultdict(lambda :0)
for prime in primelist:
    if prime>n:
        factors[n]+=1
        break
    while n%prime==0:
        n=n//prime
        factors[prime]+=1
factors[n]=1

ans=0
for i in factors:
    if i!=1:
        f=factors[i]
        for j in range(1,50):
            f-=j
            if f<0:
                break
            ans+=1
print(ans)
