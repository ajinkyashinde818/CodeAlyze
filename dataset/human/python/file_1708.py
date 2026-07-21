import sys
N, M = map(int,input().split())
A = []
B = []
for _ in range(N):
    A.append(input())
for _ in range(M):
    B.append(input())
for i in range(N - M + 1):
    for j in range(N - M + 1):
        flag = 1
        for h in range(M):
            if A[h+i][j:j+M] != B[h]:
                flag = 0
        if flag:
            print('Yes')
            sys.exit()
print('No')
