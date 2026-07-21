def main():
    N=input()
    X=len(N)
    INF=10**100
    dp=[[INF,INF] for i in range(0,X+1)]
    dp[0][0]=0
    dp[0][1]=1
    for j in range(1,X+1):
        dp[j][0]=min(dp[j-1][0]+int(N[j-1])%10,dp[j-1][1]+10-int(N[j-1])%10)
        if int(N[j-1])%10!=9:
            dp[j][1]=min(dp[j-1][1]+9-int(N[j-1])%10,dp[j-1][0]+int(N[j-1])%10+1)
        else:
            dp[j][1]=dp[j-1][1]+9-int(N[j-1])%10
    print(dp[X][0])

if __name__ == '__main__':
    main()
