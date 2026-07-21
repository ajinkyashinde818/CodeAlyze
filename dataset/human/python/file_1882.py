def solve():
    N, M = map(int, input().split())
    A = [list(input()) for i in range(N)]
    B = [list(input()) for i in range(M)]

    i = 0
    j = 0
    snipped = []
    while i + M <= N:
        for di in range(M):
            snipped.append(A[i+di][j:M+j])
        if B == snipped:
            print('Yes')
            break

        snipped = []
        j += 1
        if j + M > N:
            i += 1
            j = 0
    else:
        print('No')

    
if __name__ == '__main__':
    solve()
