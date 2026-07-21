def factorization(n):
    factors = []
    i = 2
    cnt = 0
    while i ** 2 <= n:
        while n % i == 0:
            n //= i
            cnt += 1
        if cnt > 0:
            factors.append((i, cnt))
        i += 1
        cnt = 0
    if n > 1:
        factors.append((n, 1))
    return factors


n = int(input())
print(sum([int((-1 + (1 + 8 * v[1]) ** 0.5) / 2) for v in factorization(n)]))
