import numpy as np

N, M = map(int, input().split())

A = np.array([list(input()) for _ in range(N)])
B = np.array([list(input()) for _ in range(M)])

T = N - M + 1

for i in range(T):
    for j in range(T):
        if np.sum(A[i:i+M, j:j+M] == B) == M ** 2:
            print('Yes')
            exit(0)
print('No')
