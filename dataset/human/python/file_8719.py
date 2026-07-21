import numpy as np
N,K = list(map(int, input().split()))
A = list(map(int, input().split()))
A_diff = np.diff(A)
A_diff_sum = np.sum(A_diff)
max_diff = np.max([np.max(A_diff), (N - A[-1] + A[0])])
ans = A_diff_sum - max_diff + (N - A[-1] + A[0])
print(ans)
