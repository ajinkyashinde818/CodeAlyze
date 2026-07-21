import sys

N, M = map(int,input().split())
An = [list(input()) for _ in range(N)]
Bn = [list(input()) for _ in range(M)]
for i in range(N - M + 1):
    for j in range(N - M + 1):
        flag = True
        for ii in range(M):
            for jj in range(M):
                if An[j+jj][i+ii] != Bn[ii][jj]: flag = False
        if flag is True:
            print("Yes")
            sys.exit()
print("No")
