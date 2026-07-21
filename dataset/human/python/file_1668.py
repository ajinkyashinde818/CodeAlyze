import sys

N,M = map(int,input().split())
A = []
B = []
for _ in range(N):
    A.append(input())
for _ in range(M):
    B.append(input())

for i in range(N-M+1):
    for j in range(N-M+1):
        if A[i][j:j+M] == B[0]:
            check = True
            for k in range(1,M):
                if A[i+k][j:j+M] == B[k]:
                    pass
                else:
                    check = False
                    break
            if check:
                print('Yes')
                sys.exit()
print('No')
