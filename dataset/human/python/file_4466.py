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
primes = prime_factorize(int(input()))
prime_set = set(primes)
count = 0
for p in prime_set:
    cnt = primes.count(p)
    count += 1
    i = 2
    while cnt>i:
        cnt -= i
        count += 1
        i = i + 1
print(count)
