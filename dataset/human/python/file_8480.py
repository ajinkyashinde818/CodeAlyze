import numpy as np

K, N = map(int, input().split())
A = list(map(int, input().split()))

A = np.array(A)
B = A[1:] - A[:-1]
B = np.insert(B, N-1, K+A[0]-A[N-1])

B = B.tolist()
max_A = max(B)
max_idx = B.index(max_A)

#print(B)
#print(max_A, max_idx)

print(K-max_A)
