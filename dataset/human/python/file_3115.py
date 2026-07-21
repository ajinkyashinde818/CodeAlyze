import math
from bisect import bisect


def primeFactors(n):
    ar = []
    for i in range(1, 101):
        ar.append(i * (i + 1) // 2)
    d = dict()
    while n % 2 == 0:
        if d.get(2) is None:
            d[2] = 1
        else:
            d[2] += 1
        n = n // 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            if d.get(i) is None:
                d[i] = 1
            else:
                d[i] += 1
            n = n // i
    if n > 2:
        d[n] = 1
    cnt = 0
    for i in d.values():
        if i == 1:
            cnt += 1
        else:
            b = bisect(ar, i)
            cnt += b
    return cnt


print(primeFactors(int(input())))
