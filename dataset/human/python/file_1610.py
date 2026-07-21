import sys

N, M = (int(i) for i in input().split())
A = []
B = []
for i in range(N):
    A.append(input())
for i in range(M):
    B.append(input())

for i in range(N-M+1):
    if B[0] in A[i]:
        pos = A[i].find(B[0])
        flag = 0
        for j in range(M):
            if A[i+j][pos:pos+M] == B[j]:
                pass
            else:
                flag = -1
                break
        if flag == 0:
            print("Yes")
            sys.exit()

print("No")
