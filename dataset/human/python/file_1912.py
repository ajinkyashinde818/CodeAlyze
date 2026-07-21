def solve():
    def check(i, j, m):
        for h in range(m):
            for w in range(m):
                if A[h+i][w+j] != B[h][w]:
                    return False
        return True
    N, M = map(int, input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]

    for i in range(N-M+1):
        for j in range(N-M+1):
            if check(i, j, M):
                print("Yes")
                return
    print("No")
    return

solve()
