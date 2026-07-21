from math import sqrt
from collections import Counter

def prime_factorization(n):
    counter = Counter()
    for i in range(2, int(sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            counter[i] += 1

    if n != 1:
        counter[n] += 1

    return list(counter.items())

N = int(input())

candinates = []

for p, c in prime_factorization(N):
    # print(p, c)
    i = 1
    while i <= c:
        candinates.append(pow(p, i))
        c -= i
        i += 1


candinates.sort()

# print(candinates)

count = 0
for z in candinates:
    N, r = divmod(N, z)
    if r != 0:
        break
    count += 1

print(count)
