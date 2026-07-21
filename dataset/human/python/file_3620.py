N = int(input())

def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 2
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n // i)
        i += 1
    return lower_divisors + upper_divisors[::-1]


def prime_factor(n):
    res = []
    for i in range(2,int(n**0.5)+1):
        while n % i==0:
            res.append(i)
            n = n//i
    if n != 1:
        res.append(n)
    return res

ans = 0
divisors = make_divisors(N)

if len(divisors) == 0 and N != 1:
    print(1)
    exit()

for i in divisors:
    primes = set(prime_factor(i))
    if len(primes) == 1 and N % i == 0:
        ans += 1
        N /= i
        N = int(N)

print(ans)
