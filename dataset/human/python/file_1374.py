import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))
sum_A = np.sum(A)
cumsum_A = np.cumsum(A)

ans = float('inf')
for i in range(N - 1):
    ans = min(ans, abs(sum_A - 2 * cumsum_A[i]))
print(ans)
