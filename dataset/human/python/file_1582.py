def check(s,t):
    for i in range(s,s+M):
        for j in range(t,t+M):
            if A[i][j] != B[i-s][j-t]:
                return False
    return True


N,M = map(int,input().split())

A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        if check(i,j):
            print("Yes")
            exit()

print("No")
