import copy
D, G = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(D)]

if G // 100 <= D:
    print(1)
else:
    N = 0
    for i in range(D):
        pc[i].append((i+1)*100*pc[i][0]+pc[i][1])
        N += pc[i][0]
    dp = [[0, [pc[i][0] for i in range(D)]] for j in range(N)]

    for i in range(N):
        for j in reversed(range(D)):
            if i+1 >= pc[j][0]:
                for k in range(1, pc[j][0]+1):
                    if dp[i - k][1][j] == k:
                        if dp[i][0] < dp[i - k][0] + pc[j][1] + dp[i - k][1][j]*100*(j+1):
                            dp[i][0] = dp[i - k][0] + pc[j][1] + \
                                dp[i - k][1][j]*100*(j+1)
                            dp[i][1] = copy.deepcopy(dp[i-k][1])
                            dp[i][1][j] = 0

            if dp[i-1][1][j] > 0:
                if dp[i][0] < dp[i-1][0] + (j+1)*100:
                    dp[i][0] = dp[i-1][0] + (j+1)*100
                    dp[i][1] = copy.deepcopy(dp[i-1][1])
                    dp[i][1][j] -= 1

        if dp[i][0] >= G:
            print(i+1)
            break
