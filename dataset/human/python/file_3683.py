from collections import defaultdict
def primeFact(n):
    factors = defaultdict(int)
    i = 2
    while i*i <= n:
        if n % i == 0:
            n //= i
            factors[i]+=1
        else:
            i += 1
    if n > 1:
        factors[n]+=1
    return factors

N = int(input())

if N<=1:
    print(0)
    exit()

ans=0
primes = primeFact(N)

for val in primes.values():
    i=1
    while val>=i:
        val-=i
        i+=1
        ans+=1
print(ans)
