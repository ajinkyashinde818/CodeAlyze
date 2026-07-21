import numpy as np


N = int(input())
A = np.array(input().split(), np.int32)
B = np.array(input().split(), np.int32)
C = np.array(input().split(), np.int32)

A_diff = np.zeros(A.shape)
A_diff[1:] = np.diff(A, n=1)

res = 0

for i, diff_num in zip(A, A_diff):
    res += B[i-1]
    if diff_num == 1:
        res  += C[i-2]

print(res)
