N = int(input())

def factorize(n):
    if n == 1: return []
    res = []
    x, y = n, 2
    while y * y <= x:
        while x % y == 0:
            res.append(y)
            x //= y
        y += 1
    if x > 1:
        res.append(x)
    return res

from collections import Counter

F = factorize(N)
C = Counter(F)


res = 0

if N == 1:
    print(0)
else:
    for k, v in C.items():
        tmp = 0
        while True:
            if (tmp + 1) * (tmp + 2) // 2 > v:
                res += tmp
                break
            tmp += 1

    print(res)
