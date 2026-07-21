import numpy as np

N, M = map(int, input().split())
A = np.array([[i for i in input()] for j in range(N)])
B = np.array([[i for i in input()] for j in range(M)])

found = False
for i in range(N-M+1):
    for j in range(N-M+1):
        P = A[i:i+M,j:j+M]
        if (P == B).all():
            print("Yes")
            found = True
            break
    if found: break
if not found:
    print("No")
