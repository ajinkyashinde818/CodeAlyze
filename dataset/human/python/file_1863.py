import numpy as np

N, M = [int(x) for x in input().split()]
A=[]
B=[]
for i in range(N):
    A.append(list(input()))
for j in range(M):
    B.append(list(input()))
A = np.array(A)
B = np.array(B)
for i in range(N-M+1):
    for j in range(N-M+1):
        A_ = A[i:(i+M),j:(j+M)]
        if np.array_equal(A_,B):
            print('Yes')
            exit()

print('No')
