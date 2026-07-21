from collections import defaultdict
import math

n = int(input())

primes = defaultdict(int)
t = n
for i in range(2, int(math.sqrt(n)) + 1):
    while t % i == 0:
        primes[i] += 1
        t //= i
if t != 1:
    primes[t] += 1

count = 0
for cn in primes.values():
    count += int((-1 + math.sqrt(1 + 8 * cn)) / 2)

print(count)
