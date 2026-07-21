import sys 

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]


c = N - M + 1

for ic in range(c):
    for jc in range(c):
        cnt = 0
        for i in range(M):
            for j in range(M):
                if A[ic + i][jc + j] == B[i][j]:
                    cnt += 1

        if cnt == M * M:
            print("Yes")
            sys.exit()
else:
    print("No")
