import math

N = int(input())


def prime_factorization(n):
    from collections import Counter
    counter = Counter()

    if n < 2:
        return counter

    for i in range(2, int(n ** 0.5) + 1):
        if i * i > n:
            break

        while n % i == 0:
            counter[i] += 1
            n //= i

    if n > 1:
        counter[n] += 1

    return counter


p_fact = prime_factorization(N)

cnt = 0
for _, e in p_fact.items():
    val = math.sqrt(2 * e + 0.25) - 0.5
    val = int(val)
    cnt += val

print(cnt)
