from math import sqrt
import itertools

def factorization(n):
    factors = []
    temp = n
    for i in range(2, int(sqrt(n))+1):
        if temp % i == 0:
            count = 0
            while temp % i == 0:
                count += 1
                temp //= i
            factors.append((i, count))
    if temp != 1:
        factors.append((temp, 1))
    if not factors:
        factors.append((n, 1))

    return factors


N = int(input())
factors = factorization(N)
count = 0
for a, b in factors:
    c = 0
    for i in itertools.count(1):
        c += i
        if c > b:
            break
        else:
            count += 1

if N == 1:
    print(0)
else:
    print(count)
