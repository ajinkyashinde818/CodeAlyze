n = int(input())


def prime_factorization(n):
    pmax = int(n ** 0.5 // 1) + 1

    factors = {}
    for p in range(2, pmax + 1):
        while n % p == 0:
            factors[p] = factors.get(p, 0) + 1
            n //= p
    if n != 1:
        factors[n] = factors.get(n, 0) + 1

    return factors


factors = prime_factorization(n)

answer = 0
for power in factors.values():
    n = 1
    while (n + 1) * (n + 2) // 2 <= power:
        n += 1
    answer += n



print(answer)
