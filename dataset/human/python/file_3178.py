import math
import numpy as np
n = int(input())
fac = []
sqrt_n = math.sqrt(n)
for i in range(2, int(sqrt_n)):
    if not n % i:
        fac.append(0)
    while not n % i:
        n /= i
        fac[-1] += 1
if n > sqrt_n:
    fac.append(1)
num = 0
for f in fac:
    num += np.count_nonzero(f >= np.cumsum(range(1, f+1)))
print(num)
