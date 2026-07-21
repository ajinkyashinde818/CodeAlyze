N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]
def check(dx, dy):
    cut_A = [[] for _ in range(M)]
    for i in range(dx, dx + M):
        for j in range(dy, dy + M):
            cut_A[i-dx].append(A[i][j])
    return cut_A == B

for dx in range(N-M+1):
    for dy in range(N-M+1):
        if check(dx, dy):
            print("Yes")
            exit()
print("No")
