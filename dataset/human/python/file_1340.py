N = int(input())
A = list(map(int, input().split()))

import numpy as np
sumA = np.cumsum(A)

ans = float('inf')
for i in range(0, N-1):
    x = sumA[i]
    y = sumA[-1] - x
    ans = min(abs(x-y), ans)
print(ans)
