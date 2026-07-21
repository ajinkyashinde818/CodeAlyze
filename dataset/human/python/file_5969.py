import numpy as np
input()
A = np.array(input().split(), np.int16) - 1
B = np.array(input().split(), np.int16)
C = np.array(input().split(), np.int16)
print(B.sum() + C[A[:-1][A[1:] - A[:-1] == 1]].sum())
