import numpy as np

N = int(input())
A = np.array([int(x) for x in input().split()], dtype = np.int64)

abs_A = np.abs(A)
abs_sum = abs_A.sum()
abs_min = abs_A.min()
negatives = (A < 0).sum()

ans = abs_sum if negatives%2 == 0 else abs_sum - 2*abs_min
print(ans)
