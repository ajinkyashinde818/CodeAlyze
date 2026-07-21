import numpy as np
n = int(input())
a = np.array([int(i) for i in input().split()])
if 0 in a or len(a[a < 0]) % 2 == 0:
    print(int(np.abs(a).sum()))
else:
    m = np.abs(a).min()
    print(int(np.abs(a).sum() - 2 * m))
