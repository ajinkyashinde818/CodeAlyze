import sys

def resolve():
    N, M = map(int, input().split())
    A = []
    for i in range(N):
        A.append(input())
    B = []
    for i in range(M):
        B.append(input())

    for i in range(N - M + 1):
        for j in range(N - M + 1):
            for k in range(M):
                if B[k] != A[i+k][j:j+M]:
                    break
                if k == M-1:
                    print('Yes')
                    return

    print('No')

if __name__ == "__main__":
    resolve()
