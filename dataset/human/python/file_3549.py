import math
import numpy as np

def myfunc(n):
    f = []
    c = 0
    r = int(n ** 0.5)
    for i in range(2, r + 2):
        while n % i == 0:
            c += 1
            n = n // i
        if c != 0:
            f.append([i, c])
            c = 0

    if n != 1:
        f.append([n, 1])

    return f

N = int(input())
M = (math.sqrt(N)) + 1

L = np.array([1, 3, 6, 10, 15, 21, 28, 36])

f = myfunc(N)
count = 0
for _, c in f:
    if c == 1:
        count += c
    else:
        i = (L <= c).sum()
        count += i

print(count)
