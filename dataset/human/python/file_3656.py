import math
N = int(input())
if N <= 1:
    print(0)
    exit()

L = math.ceil(math.sqrt(N)) + 1
isPrime = [True] * L
isPrime[0] = isPrime[1] = False
primes = []
for n in range(2, L):
    if isPrime[n]:
        primes.append(n)
        isPrime[2*n::n] = [False] * ((L-n-1) // n)

ans = 0
for p in primes:
    d = p
    while N % d == 0:
        ans += 1
        N //= d
        d *= p
    while N % p == 0:
        N //= p

if N != 1:
    ans += 1
print(ans)
