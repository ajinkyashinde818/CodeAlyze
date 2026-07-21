import numpy as np
N = int(input())
A = np.array(input().split(), dtype=np.int64)

neg = np.count_nonzero(A[A < 0])
if neg % 2 == 0 or 0 in A:
    ans = np.abs(A).sum()
else:
    tmp = np.abs(A).min()
    ans = np.abs(A).sum() - 2 * tmp

print(ans)
