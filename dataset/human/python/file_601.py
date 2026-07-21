import numpy as np
N = int(input())
A = list(map(int, input().split()))
A = np.array(A, dtype = 'int64')
k = np.where(A < 0)
l = len(k[0])
A = np.abs(A)
if l % 2 == 0:
    print(np.sum(A))
else:
    print(np.sum(A) - 2 * np.min(A))
