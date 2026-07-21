N, M = map(int, input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]

def check():
    for i in range(N-M+1):
        for j in range(N-M+1):
            if B[0] == A[i][j:j+M]:
                for k in range(1,M):
                    if B[k] != A[i+k][j:j+M]:
                        break
                else:
                    return True
    return False

if check():
    print('Yes')
else:
    print('No')
