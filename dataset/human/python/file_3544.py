import math
from collections import defaultdict
N = int(input())

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

f = prime_factors(N)
f_dict = defaultdict(int)
for i in f:
    f_dict[i] += 1

def triangle_map(m):
    # return math.ceil((-1+math.sqrt(1+8*m))/2)
    i = 1
    while i*(i+1) <= 2*m:
        i += 1
    return i-1

ans = 0
for i in f_dict:
    ans += triangle_map(f_dict[i])

print(ans)
