import collections

N = int(input())

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


primes = collections.Counter(prime_factorize(N))
ans = 0
for prime, num in primes.items():
    n = 1
    while (n + 1) * (n + 2) / 2 <= num:
        n += 1
    ans += n

print(ans)
