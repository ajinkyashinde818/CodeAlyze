import numpy as np
from sys import maxsize

n = int(input())
a = np.array(list(map(int, input().split())))

cumsum = np.cumsum(a)
res = maxsize
for i in range(n-1):
    val = abs(cumsum[i] - (cumsum[-1] - cumsum[i]))
    if val < res:
        res = val

print(res)
