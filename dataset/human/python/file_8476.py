import numpy as np

K, N = list(map(int, input().split()))
A = list(map(int, input().split()))

B = []
for i in range(1, len(A)):
    B.append(A[i] - A[i-1])

B.append(K - A[-1] + A[0])

max_dist = np.max(B)

print(K - max_dist)
