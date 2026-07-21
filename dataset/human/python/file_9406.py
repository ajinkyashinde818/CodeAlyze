def main():
    N, K = (int(i) for i in input().split())
    A = [int(i) for i in input().split()]
    c = [[0]*(N+1) for _ in range(61)]
    c[0][1:] = A[:]
    for i in range(60):
        for j in range(1, N+1):
            c[i+1][j] = c[i][c[i][j]]
    i = 1 << 60
    j = 1
    k = 60
    while K > 0:
        if i <= K:
            K -= i
            j = c[k][j]
        i >>= 1
        k -= 1
    print(j)


if __name__ == '__main__':
    main()
