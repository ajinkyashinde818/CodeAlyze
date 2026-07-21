from fractions import gcd
import numpy as np

N = int(input())
A = np.array(list(map(int, input().split())))

if len(A[A < 0]) % 2 == 0:
    print(np.sum(np.abs(A)))
else:
    minabs_idx = np.argmin(np.abs(A))
    a = np.sum(np.abs(A)) - np.abs(A[minabs_idx])
    b = np.abs(A[minabs_idx])
    print(a - b)
