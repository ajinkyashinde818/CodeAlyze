from bisect import bisect_right
from collections import defaultdict
import numpy as np


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


N = int(input())

if N == 1:
    print(0)
    exit()

primes = factorization(N)

A = np.arange(1, 100)
cumsum_A = A.cumsum()
# print(cumsum_A)

if len(primes) == 0:
    print(1)
    exit()

ans = 0
for _, value in primes:
    idx = bisect_right(cumsum_A, value)
    ans += idx
print(ans)
