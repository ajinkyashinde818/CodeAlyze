def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    A = [input().rstrip('\n') for _ in range(N)]
    B = [input().rstrip('\n') for _ in range(N)]

    for i in range(N-M+1):
        for j in range(N-M+1):
            ok = 1
            for k in range(M):
                for l in range(M):
                    if A[i+k][j+l] != B[k][l]:
                        ok = 0
            if ok:
                print('Yes')
                exit()
    print('No')


if __name__ == '__main__':
    main()
