import numpy as np
N, M = map(int, input().split())

A = np.array([[1 if i == "#" else 0 for i in input()] for _ in range(N)])
B = np.array([[1 if i == "#" else 0 for i in input()] for _ in range(M)])

if N == M:
    if np.all(A == B):
        print("Yes")
    else:
        print("No")
else:
    for i in range(N - M): # 横移動
        for j in range(N - M): # 縦移動
            if np.all(A[i: M + i, j: M + j]== B):
                print("Yes")
                exit()
    print("No")
