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

prime_factors = collections.Counter(prime_factorize(N))

counter = 0
for p in prime_factors:
    e = 1
    while prime_factors[p] >= e:
        N //= p ** e
        prime_factors[p] -= e
        e += 1
        counter += 1

print(counter)
