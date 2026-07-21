import math
from collections import Counter

N = int(input())

max_itr = math.ceil(math.sqrt(N))

factors = []
while True:
    for i in range(2, max_itr):
        if N%i == 0:
            N = N // i
            factors.append(i)
            break
    else:
        if N != 1:
            factors.append(N)
        break

c = Counter(factors)
f = lambda x: math.floor((math.sqrt(8*x+1) - 1)/2)
print(sum(f(v) for v in c.values()))
