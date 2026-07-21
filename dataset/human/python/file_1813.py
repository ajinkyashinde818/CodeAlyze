def main():
    N, M = map(int, input().split())
    A = []
    B = []

    for i in range(N):
        B.append(input().split()[0])

    for _ in range(M):
        A.append(input().split()[0])

    for i in range(N - M + 1):
        for j in range(N - M + 1):
            f = True
            for m in range(M):
                for n in range(M):
                    if B[i + m][j + n] != A[m][n]:
                        f = False
                        break
                if f is False:
                    break
            if f is True:
                print("Yes")
                return
    print("No")        

main()
