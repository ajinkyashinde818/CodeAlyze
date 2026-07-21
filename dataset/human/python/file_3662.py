import sys
from collections import Counter

sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline


def prime_factorization(n):
    prime_arr = []
    while n % 2 == 0:
        prime_arr.append(2)
        n //= 2

    f = 3
    while f * f <= n:
        if n % f == 0:
            prime_arr.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        prime_arr.append(n)
    return prime_arr


N = int(input())
c = Counter(prime_factorization(N))
counter = 0

for v in c.values():
    t = 1
    while v - t >= 0:
        counter += 1
        v -= t
        t += 1

print(counter)
