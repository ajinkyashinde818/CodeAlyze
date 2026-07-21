import math
from collections import Counter

def get_prime_factors(n):
    if n == 1:
        return []
    else:
        limit = int(math.sqrt(n))
        for i in range(2, limit + 1):
            if n % i == 0:
                return [i] + get_prime_factors(n // i)
        return [n]


N = int(input())

operations = 0
prime_factors = get_prime_factors(N)
for p, count in Counter(prime_factors).items():
    for i in range(1, count + 1):
        if i <= count:
            operations += 1
            count -= i
        else:
            break
print(operations)
