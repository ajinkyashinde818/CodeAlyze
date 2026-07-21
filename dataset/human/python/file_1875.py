import sys
import numpy as np

N, M = list(map(int, input().split()))
A = []
for _ in range(N):
    A.append(list(input()))
B = []
for _ in range(M):
    B.append(list(input()))

A = np.array(A)
B = np.array(B).flatten()

for row in range(N - M + 1):
    for col in range(N - M + 1):
        patch = A[row:row + M, col:col + M].flatten()
        if str(patch) == str(B):
            print('Yes')
            sys.exit()
print('No')
