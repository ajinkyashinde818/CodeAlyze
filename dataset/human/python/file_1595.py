N, M = map(int, input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]

ans = 'No'


def check(x, y):
    for i in range(M):
        for j in range(M):
            if A[x + i][y + j] != B[i][j]:
                return False
    return True


for i in range(N - M + 1):
    for j in range(N - M + 1):
        if check(i, j):
            ans = 'Yes'

print(ans)
