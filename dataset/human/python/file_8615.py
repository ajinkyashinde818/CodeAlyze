import numpy as np

k, n = map(int, input().split())
A = list(map(int, input().split()))
A.append(A[0]+k)
A = np.array(A)

A_shift = np.roll(A, -1)
A_diff = A_shift - A
ans = k - np.max(A_diff[:-1])
print(str(ans))
