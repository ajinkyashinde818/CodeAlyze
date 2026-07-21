n = int(input())


def prime_factorize(n):
    res = []
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            res.append(i)
            n //= i
    if n != 1:
        res.append(n)
    return res


fac = prime_factorize(n)

from collections import Counter

ctr = Counter(fac)

ans = 0
for val in ctr.values():
    cnt = 1
    while val - cnt >= 0:
        ans += 1
        val -= cnt
        cnt += 1


print(ans)
