import numpy as np

N, M = map(int, input().split())
A = []
for i in range(N):
    S = input()
    A.append([S[i] for i in range(len(S))])
A = np.array(A)
B = []
for i in range(M):
    S = input()
    B.append([S[i] for i in range(len(S))])
for i_raw in range(N - M + 1):
    for j_col in range(N - M + 1):
        if (A[i_raw : i_raw + M, j_col : j_col + M] == B).all():
            print("Yes")
            exit()
print("No")
