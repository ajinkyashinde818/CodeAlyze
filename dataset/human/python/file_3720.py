def prime_factorization(n):  # 素因数分解
    res = []
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            res.append((i, cnt))
    if n > 1:
        res.append((n, 1))
    return res


N = int(input())
pf = prime_factorization(N)

ans = 0
for _, f in pf:
    x = 1
    while f >= x:
        ans += 1
        f -= x
        x += 1

print(ans)
