def main():
    N = int(input())
    A = [int(a) for a in input().split()]
    dp = [[0, 0] for _ in range(N)]
    dp[1][0] = A[0]+A[1]
    dp[1][1] = -(A[0]+A[1])
    for i in range(2, N):
        dp[i][0] = max(dp[i-1][0] + A[i], dp[i-1][1] + A[i])
        dp[i][1] = max(dp[i-1][0]-2*A[i-1]-A[i], dp[i-1][1]+2*A[i-1]-A[i])
    # print(A)
    # print(dp)
    return max(dp[N-1])


if __name__ == '__main__':
    print(main())
