N = int(input())


def prime_factorize(n):
    res, a = [], 2
    while a*a <= n:
        if n % a == 0:
            ex = 0
            while n % a == 0:
                ex += 1
                n //= a
            res.append([a, ex])
        a += 1
    if n != 1:
        res.append([n, 1])
    return res

cnt = [0] * 100
now = 1
tmp = 0
for i in range(1, 100):
    if tmp >= now+1:
        now += 1
        tmp = 0
    cnt[i] = now
    tmp += 1

primes = prime_factorize(N)
ans = 0
for p, i in primes:
    ans += cnt[i]

print(ans)
