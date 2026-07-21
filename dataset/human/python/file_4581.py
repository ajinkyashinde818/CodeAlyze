import math
def get_prime(n):
    if n <= 1:
        return []
    prime = [2]
    if n > 2:
        limit = int(math.sqrt(n))
        odd = [i for i in range(3, n + 1, 2)]
        while limit >= odd[0]:
            prime.append(odd[0])
            odd = [j for j in odd if j % odd[0] != 0]
        prime += odd
    return prime

from collections import defaultdict
def prime_factorization(n):
    if n <= 1:
        return {}
    else:
        # print(int(math.sqrt(n)))
        prime = get_prime(int(math.sqrt(n)))
        dct = defaultdict(int)
        for p in prime:
            while n % p == 0:
                dct[p] += 1
                n //= p
        if n != 1:
            dct[n] += 1
        dct = dict(dct)
        return dct

n = int(input())
pf = prime_factorization(n)

Z = []
for k, v in pf.items():
    for i in range(1, v + 1):
        Z.append(k ** i)
Z.sort()
count = 0
for z in Z:
    if n % z == 0:
        count += 1
        n //= z
    if n == 1:
        break

print(count)
