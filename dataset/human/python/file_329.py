import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())))

if np.count_nonzero(a < 0) % 2 == 0:
    print(np.abs(a).sum())
else:
    b = np.abs(a)
    m = b.min()
    print(b.sum() - 2 * m)
