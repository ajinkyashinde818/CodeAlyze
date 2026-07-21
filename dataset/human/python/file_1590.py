import numpy as np
N, M = map(int, input().split())
A = np.array([[j for j in input()] for i in range(N)])
B = np.array([[j for j in input()] for i in range(M)])
ans = 'No'
for l in range(N-M+1):
    for d in range(N-M+1):
        if np.array_equal(A[l:l+M,d:d+M], B):
            ans = 'Yes'
print(ans)
