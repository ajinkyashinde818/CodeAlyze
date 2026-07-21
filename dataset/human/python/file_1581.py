def is_same(si, sj):
    for i in range(M):
        for j in range(M):
            if gridsA[sj + j][si + i] != gridsB[j][i]:
                return False
    return True


N, M = map(int, input().split())
gridsA = [input() for _ in range(N)]
gridsB = [input() for _ in range(M)]

if N == M:
    if is_same(0, 0):
        print('Yes')
    else:
        print('No')
else:
    for i in range(N - M):
        for j in range(N - M):
            if is_same(i, j):
                print('Yes')
                exit()
    print('No')
