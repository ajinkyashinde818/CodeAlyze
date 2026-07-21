import numpy as np
N,M = map(int,input().split())
A = np.array([list(input()) for i in range(N)])
B = np.array([list(input()) for i in range(M)])
for i in range(N):
    for j in range(N):
        check = A[i:i+M,j:j+M]
        if check.shape != (M,M):
            continue
        if (check==B).all():
            print("Yes")
            exit()
print("No")
