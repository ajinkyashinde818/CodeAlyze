from numba import njit
import numpy as np


def main(N, K, A):
    d = np.zeros(N, np.int32)
    d = d-1
    p = 1
    for i in range(K):
        if d[p-1] == -1:
            d[p-1] = i
            p = A[p-1]
        else:
            p = A[p-1]
            loop = i-d[p-1]+1
            nokori = (K-d[p-1]) % loop
            for _ in range(nokori):
                p = A[p-1]
            return p
    return p


N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = main(N, K, A)
print(ans)
