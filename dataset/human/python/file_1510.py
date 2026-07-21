import numpy as np
N, M = map(int,input().split())
A = [list(map(lambda x: 1 if x == "." else 0, list(input()))) for n in range(N)]
B = [list(map(lambda x: 1 if x == "." else 0, list(input()))) for m in range(M)]

A = np.array(A)
B = np.array(B)

flag = False
for r in range(N-M+1):
    for c in range(N-M+1):
        if (A[r:r+M, c:c+M] == B).all():
            flag = True
if flag:
    print("Yes")
else:
    print("No")
