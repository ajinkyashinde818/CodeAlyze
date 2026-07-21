def prime_fact(n):
    primes = []
    i = 2
    while i * i <= n:
        cnt = 0
        while n % i == 0:
            n //= i
            cnt += 1
        if cnt:
            primes.append([i, cnt])
        i += 1

    if n != 1:
        primes.append([n, 1])
    return primes

n = int(input())

primes = prime_fact(n)

cnt = 0
for i, j in primes:
    k = 1
    while k <= j:
        j -= k
        k += 1
        cnt += 1

print(cnt)
