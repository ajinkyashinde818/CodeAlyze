from collections import defaultdict


def prime_factorization(n):
    divs = defaultdict(int)

    while n % 2 == 0:
        divs[2] += 1
        n //= 2

    i = 3
    while i <= int(n ** .5) + 1:
        while n % i == 0:
            divs[i] += 1
            n //= i
        i += 2
    if n != 1:
        divs[n] += 1

    return divs

import bisect
N = int(input())
divs = prime_factorization(N)

MAX_VAL = 13
table = [n * (n + 1) // 2 for n in range(1, MAX_VAL)]
ans = 0
for key, value in divs.items():
    idx = bisect.bisect_left(table, value)
    ans += idx + 1 if table[idx] == value else idx

print(ans)
