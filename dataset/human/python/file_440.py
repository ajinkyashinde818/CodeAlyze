import numpy as np

N = int(input())
A = list(map(int,input().split()))

A = np.array(A)
idx_minabs = np.argmin(np.abs(A))
n_minus = np.sum(A < 0) - (A[idx_minabs] < 0)

ans = np.sum(np.abs(A)) - np.abs(A[idx_minabs]) + (2*((n_minus+1)%2)-1)*A[idx_minabs]

print(ans)
