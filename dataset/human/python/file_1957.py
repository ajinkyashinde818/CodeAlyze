def cmp(A, B, i, j, N, M):
    for y in range(M):
        for x in range(M):
            if A[i+y][j+x] != B[y][x]:
                return False
    return True

def main():
    A = []
    B = []
    [N, M] = list(map(int, input().split()))
    for i in range(N):
        A.append(input())
    for i in range(M):
        B.append(input())

    for i in range(N-M+1):
        for j in range(N-M+1):
            if cmp(A, B, i, j, N, M):
                print("Yes")
                return
    print("No")
    return

main()
