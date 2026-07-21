import collections
import bisect

n = 10 ** 6 + 10
fl = [1] * n
fl[0] = 0
fl[1] = 0
lprime = []
for i in range(n):
    if fl[i] == 1:
        lprime.append(i)
        ti = i * 2
        while ti < n:
            fl[ti] = 0
            ti += i


def prime_factorize(n):
    global lprime
    a = []
    for p in lprime:
        if p * p > n:
            break
        while n % p == 0:
            a.append(p)
            n //= p
    if n != 1:
        a.append(n)
    return a


N = int(input())
tres = prime_factorize(N)
ctres = collections.Counter(tres)
sl = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66]
res = 0
for c in ctres.values():
    res += bisect.bisect_right(sl, c)
print(res)
