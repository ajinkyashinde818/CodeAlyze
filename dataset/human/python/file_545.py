import numpy as np
input()
A = np.array(input().split(), dtype=np.int64)
S = np.sign(A)
A = np.sort(np.abs(A))
a = A[0]
print(A.sum() if 0 in S or not ((S == -1).sum() & 1) else A.sum() - a * 2)
