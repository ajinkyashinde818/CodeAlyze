N, M = map(int, raw_input().split())
A = [raw_input() for _ in range(N)]
B = [raw_input() for _ in range(M)]


def check(i, j):
    for k in range(M):
        if A[i+k][j:j+M] != B[k]:
            return False
    return True


for i in range(N-M+1):
    for j in range(N-M+1):
        if check(i, j):
            print "Yes"
            exit()
print "No"
