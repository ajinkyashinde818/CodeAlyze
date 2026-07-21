if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    canReach = [[[False for _ in range(51)] for _ in range(N)] for _ in range(50)]  # k, n, a

    for k in range(50):
        for n in range(N):
            canReach[k][n][B[n]] = True

    for k in range(1, 50):
        for n in range(N):
            for a in range(51):
                if canReach[k - 1][n][a] or canReach[k - 1][n][a % k]:
                    canReach[k][n][a] = True

    aList = [[[False for _ in range(51)] for _ in range(N)] for _ in range(50)]  # k, n, a
    for n in range(N):
        aList[49][n][A[n]] = True

    ans = 0
    for k in reversed(range(1, 50)):
        # 到達可能かどうかチェック
        for n in range(N):
            judge = False
            for a in range(51):
                if aList[k][n][a] and canReach[k][n][a]:
                    judge = True
                    break
            if not judge:
                print(-1)
                exit()
        # kを使わないで行けるかどうかチェック
        shouldUseK = False
        for n in range(N):
            judge = False
            for a in range(51):
                if aList[k][n][a] and canReach[k - 1][n][a]:
                    judge = True
                    break
            if not judge:
                shouldUseK = True
                break

        if shouldUseK:
            ans += 2 ** k
            for n in range(N):
                for a in range(51):
                    if aList[k][n][a]:
                        aList[k - 1][n][a] = True
                        aList[k - 1][n][a % k] = True
        else:
            for n in range(N):
                for a in range(51):
                    if aList[k][n][a]:
                        aList[k - 1][n][a] = True

    print(ans)
