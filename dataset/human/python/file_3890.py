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

l = prime_factorize(N)

ans = 0
for prime in set(l):
    n_prime = l.count(prime)
    i = 1
    while (i + 2) * (i + 1) / 2 <= n_prime:
        i += 1
    ans += i

print(ans)
