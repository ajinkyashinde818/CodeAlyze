def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    dp = [[0,0] for i in range(N)]
    dp[0][0] = A[0]
    dp[0][1] = - A[0]
    for i in range(N-2):
        dp[i+1][0] = max(dp[i][0]+A[i+1],dp[i][1] - A[i+1])
        dp[i+1][1] = max(dp[i][0] - A[i+1],dp[i][1] + A[i+1])
    dp[N-1][0] = dp[N-2][0] + A[N-1]
    dp[N-1][1] = dp[N-2][1] - A[N-1]
    return max(dp[N-1])

if __name__ == '__main__':
    print(main())
