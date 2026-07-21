import numpy as np

N = int(input())

A = list(map(int, input().split()))
A = np.array(A)
A_abs = np.abs(A)
M = np.sum(A_abs)
m = np.min(A_abs)

if np.sum(A < 0) % 2 == 0:
	print(M)
else:
	print(M - 2 * m)
