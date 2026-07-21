n = int(input())
if n == 1:
    print(0)
    exit()

def primes_factraizar(n):
    rn = int(n**0.5)
    is_prime = [True]*(rn+1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2,rn+1):
        if not is_prime[i]:
            continue
        for j in range(i*2,rn+1,i):
            is_prime[j] = False
        return [i for i in range(rn+1) if is_prime[i]]
primes = primes_factraizar(n)

divisors = []
for i in primes:
    if n % i == 0:
        divisors.append(i)

divisors.sort()

if divisors == []:
    print(1)
    exit()
ans = 0

for i in divisors:
    if i == 1:
        continue

    c = 0

    while n%i == 0:
        n = n // i
        c += 1
    
    d=0

    for count in range(1,1000):
        if c >= d+count:
            ans += 1
            d+=count
        else:
            break
if not n == 1:
    ans += 1

print(ans)
