def search():
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            if all(B[k] == A[i + k][j:j + M] for k in range(M)):
                return 'Yes'
    return 'No'


N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
print(search())
