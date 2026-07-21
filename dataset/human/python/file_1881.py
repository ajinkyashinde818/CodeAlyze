N, M = map(int, input().split())
A = [input() for i in range(N)]
B = [input() for i in range(M)]
def _search(i, j):
    flag = True
    for k in range(M):
        for l in range(M):
            flag &= A[i+k][j+l] == B[k][l]
            if not flag:
                return flag
    return flag

def search():
    for i in range(N-M+1):
        for j in range(N-M+1):
            if _search(i, j):
                return 'Yes'
    return 'No'
print(search())
