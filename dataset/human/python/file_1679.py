def main():
    N, M = map(int, input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]

    for h in range(N - M + 1):
        for w in range(N - M + 1):
            flag = True
            for i in range(M):
                for j in range(M):
                    if A[h + i][w + j] == B[i][j]:
                        continue
                    else:
                        flag = False
                        break
                if not flag:
                    break
            if flag:
                print("Yes")
                return
    else:
        print("No")


main()
