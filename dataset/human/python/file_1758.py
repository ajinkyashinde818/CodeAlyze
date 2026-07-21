def main():
    N, M = map(int, input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]
    for i in range(N-M+1):
        for j in range(N-M+1):
            ok = True
            for x in range(M):
                for y in range(M):
                    if A[i+x][j+y] != B[x][y]:
                        ok = False
            if ok:
                print("Yes")
                return
    print("No")


if __name__ == "__main__":
    main()
