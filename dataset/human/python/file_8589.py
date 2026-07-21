import numpy as np
K, N = map(int, input().split())
A = np.array(input().split(), dtype=np.int64)
B = A + K

A = np.concatenate((A, B)).tolist()
ans = 10 ** 18
for i in range(N):
    d = A[i + N - 1] - A[i]
    ans = min(d, ans)

print(ans)
