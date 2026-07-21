N, M = list(map(int,input().split()))
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
C = [[]*M for _ in range(N)]

def match(i,j):
    for k in range(M):
        if A[i+k][j:j+M] != B[k]:return False
    return True

def a():
    for i in range(N-M+1):
        for j in range(N-M+1):
            if match(i,j):return "Yes"
    return "No"

print(a())
