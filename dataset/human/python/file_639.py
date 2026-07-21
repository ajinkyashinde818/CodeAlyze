def resolve():
    N = int(input())
    A = [0]+list(map(int, input().split()))
    dp = [[None for _ in range(2)] for _ in range(N+1)]
    dp[0][0] = 0
    dp[0][1] = -float("inf")
    for i in range(1, N+1):
        dp[i][0] = max(dp[i-1][0]+A[i], dp[i-1][1]-A[i])
        dp[i][1] = max(dp[i-1][0]-A[i], dp[i-1][1]+A[i])
    print(dp[N][0])



if '__main__' == __name__:
    resolve()
