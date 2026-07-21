import sys
import numpy as np

N = int(input())
A = list(map(int, input().split()))

count = 0
for i in range(N):
    if A[i] < 0:
        count += 1

A_abs = np.abs(A)
if count % 2 == 0:
    print(np.sum(A_abs))
else:
    print(np.sum(A_abs) - 2 * np.min(A_abs))
