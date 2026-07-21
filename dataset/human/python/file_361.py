import numpy as np
N = int(input())
a = np.array(list(map(int, input().split())))

tmp = sum(np.abs(a))
if np.count_nonzero(a < 0)%2 == 0:
    print(tmp)
else:
    ind = np.argmin(np.abs(a))
    print(tmp-abs(a[ind])*2)
