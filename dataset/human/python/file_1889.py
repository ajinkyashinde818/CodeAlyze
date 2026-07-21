import sys

N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

def solve(i, j):
    for a in range(M):
        for b in range(M):
            if A[i+a][j+b] != B[a][b]:
                return False
            else:
                continue
    return True

for i in range(N - M + 1):
    for j in range(N - M + 1):
        if solve(i, j):
            print("Yes")
            sys.exit()
print("No")
