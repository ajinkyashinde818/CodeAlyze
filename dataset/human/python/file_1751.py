import numpy as np
N, M = map(int, input().split())

A = []
B = []
for _ in range(N):
    tmp = input()
    tmp = tmp.replace("#", "1")
    tmp = tmp.replace(".", "2")
    tmp = [int(i) for i in tmp]
    A.append(tmp)

for _ in range(M):
    tmp = input()
    tmp = tmp.replace("#", "1")
    tmp = tmp.replace(".", "2")
    tmp = [int(i) for i in tmp]
    B.append(tmp)

A = np.array(A)
B = np.array(B)

ans = 0
for i in range(N-M+1):
    for j in range(N-M+1):
        if np.all(A[i:i+M, j:j+M] == B):
           ans = 1

if ans == 1:
    print("Yes")
else:       
    print("No")
