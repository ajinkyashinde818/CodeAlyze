import numpy as np
import sys

n = int(next(sys.stdin))
a = np.array(list(map(int, next(sys.stdin).split())))
j = np.arange(n) + 1

if np.any(a.sum() % j.sum() > 0):
    print('NO')
    exit()

s = a.sum() // j.sum()
k = s - (a[1:] - a[:-1])
if np.all(k >= 0) and np.all(k % n == 0):
    print('YES')
else:
    print('NO')
