N, M = map(int, input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]

def check(i, j):
    for ii in range(M):
        for jj in range(M):
            if A[i + ii][j + jj] != B[ii][jj]:
                return False
    return True

for i in range(N - M + 1):
    for j in range(N - M + 1):
        if check(i, j):
            print("Yes")
            exit()
print("No")
