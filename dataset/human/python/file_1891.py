import sys

N, M = map(int, input().split())

As = []
for i in range(N):
    As.append(list(input()))

Bs = []
for i in range(M):
    Bs.append(list(input()))


def isEqual(A_i, A_j):
    try:
        for i in range(M):
            for j in range(M):
                if As[A_i+i][A_j+j] != Bs[i][j]:
                    return
    except IndexError:
        return

    print('Yes')
    sys.exit(0)


for A_i in range(N):
    for A_j in range(N):
        isEqual(A_i, A_j)

print('No')
