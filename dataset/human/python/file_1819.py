import sys
N, M = [int(i) for i in input().split()]

A = [[i for i in input()] for j in range(N)]
B = [[i for i in input()] for k in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        diff = 0

        for k in range(M):
            for l in range(M):
                if A[i+k][j+l] != B[k][l]:
                    diff = 1
                    break

            if diff == 1:
                break

        if diff == 0:
            print('Yes')
            sys.exit()

print('No')
