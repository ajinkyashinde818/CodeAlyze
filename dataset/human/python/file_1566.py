from sys import stdin

n, m = map(int, stdin.readline().split())
A = []
B = []
for _ in range(n):
    A.append(stdin.readline().strip())
for _ in range(m):
    B.append(stdin.readline().strip())


def is_in(B, A):
    def cmp(A, B, x, y):
        for i in range(m):
            for j in range(m):
                if A[i+y][j+x] != B[i][j]:
                    return False
        return True

    x_shift = len(A[0]) - len(B[0])
    y_shift = len(A) - len(B)
    for x in range(0, x_shift+1):
        for y in range(0, y_shift+1):
            result = cmp(A, B, x, y)
            if result:
                return True
    return False

if is_in(B, A):
    print('Yes')
else:
    print('No')
