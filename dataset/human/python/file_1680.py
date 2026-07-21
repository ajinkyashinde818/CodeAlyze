N, M = map(int, raw_input().split())
A = [None] * N
for i in xrange(N):
    A[i] = list(raw_input())
B = [None] * M
for i in xrange(M):
    B[i] = list(raw_input())


def find(x, y):
    for i in xrange(M):
        for j in xrange(M):
            if A[y + i][x + j] != B[i][j]:
                return False
    return True

found = False
for y in xrange(N - M + 1):
    for x in xrange(N - M + 1):
        if find(x, y):
            found = True
            break
    if found:
        break
print 'Yes' if found else 'No'
