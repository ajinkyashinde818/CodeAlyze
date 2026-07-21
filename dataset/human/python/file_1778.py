import sys
N, M = map(int, input().split())
A = [list(map(str, input())) for _ in range(N)]
B = [list(map(str, input())) for _ in range(M)]
for i in range(N - M + 1):
    for j in range(N - M + 1):
        OK = True
        for k in range(M):
            for l in range(M):
                if A[i + k][j + l] != B[k][l]:
                    OK = False
                    break
            if not OK:
                break
        if OK:
            print('Yes')
            sys.exit()
print('No')
