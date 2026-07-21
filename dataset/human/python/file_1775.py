import sys

N, M = map(int, input().split())

A = [list(sys.stdin.readline()) for i in range(N)]

B = [list(sys.stdin.readline()) for i in range(M)]

for x in range(N-M+1):
    for y in range(N-M+1):
        flag = 0
        for i in range(M):
            for j in range(M):
                if A[x+i][y+j] != B[i][j]:
                    flag = 1
        if flag == 0:
            print('Yes')
            exit()

print('No')
