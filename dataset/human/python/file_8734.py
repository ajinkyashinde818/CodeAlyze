import numpy as np

K, N = map(int, input().split())
A = np.array(list(map(int, input().split())))
tmp = K - A[-1]

for i in range(N-1, 0, -1):
    A[i] = A[i] - A[i-1]

A[0] += tmp

A = np.sort(A)
print(np.sum(A[:-1]))
