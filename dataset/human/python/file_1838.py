N, M = map(int, input().split())

a_mat = [input() for _ in range(N)]
b_mat = ''.join([input() for _ in range(M)])


def to_vectors(mat, size=M):
    vectors = []
    for h in range(N-M+1):
        for w in range(N-M+1):
            tmp = [mat[h+i][w:w+M] for i in range(M)]
            vectors.append(''.join(tmp))
    return vectors


if b_mat in to_vectors(a_mat, M):
    print('Yes')
else:
    print('No')
