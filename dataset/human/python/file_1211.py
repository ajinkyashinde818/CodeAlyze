import numpy as np
n = int(input())
a = np.array([int(i) for i in input().split()])
cumsum = np.cumsum(a)
s = cumsum[-1]
m = float('inf')
for i in range(n - 1):
    t = cumsum[i]
    m = min(m, abs(2 * t - s))
print(m)
