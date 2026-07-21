N, M = map(int, input().split())

mat_N = []
for _ in range(N):
    mat_N.append(input())
mat_M = []
for _ in range(M):
    mat_M.append(input())

def chk(y, x):
    for k in range(M):
        if mat_N[y + k][x:M + x] != mat_M[k]:
            return False
    return True

if M <= N:
    for y in range(N-M+1):
        for x in range(N-M+1):
            if chk(y, x):
                print("Yes")
                exit()
print("No")
