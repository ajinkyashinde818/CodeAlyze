N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(list(input()))
for j in range(M):
    B.append(list(input()))
import copy
CA = copy.deepcopy(B)
ans = -1
for i in range(N - M + 1):
    for l in range(N - M + 1):
        for j in range(M):
            for k in range(M):
                CA[j][k] = A[i + j][l + k]
        if CA == B:
            print("Yes")
            ans = 1
            break
    if ans == 1:
        break
if ans == -1:
    print("No")
