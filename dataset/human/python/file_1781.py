import sys

N, M = map(int, input().split())

A = [list(sys.stdin.readline().strip()) for _ in range(N)]
B = [list(sys.stdin.readline().strip()) for _ in range(M)]


def check(y, x):
    for i in range(y, y + M):
        if A[i][x:x + M] != B[i - y]:
            return False
    return True

if N == M:
    print("Yes") if check(0, 0) else print("No")
else:
    for i in range(N - M):
        for j in range(N - M):
            if A[i][j] == B[0][0]:
                if check(i, j):
                    print("Yes")
                    exit()
    print("No")
