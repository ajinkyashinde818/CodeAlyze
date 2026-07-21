import numpy as np
n = int(input())
a = np.array(tuple(map(int, input().split())))
b = len(np.where(a < 0)[0])
a = abs(a)
if b % 2 == 0:
    print(np.sum(a))
else:
    print(np.sum(a) - 2 * np.min(a))
