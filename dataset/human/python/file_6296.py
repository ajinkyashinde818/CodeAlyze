import sys
def main():
    input=sys.stdin.readline
    S=input().strip()
    dp=[[0,0] for i in range(len(S)+1)]
    dp[0][1]=1
    for i in range(1,len(S)+1):
        for j in (0,1):
            if j==0:
                dp[i][0]=min(dp[i-1][0]+int(S[i-1]),dp[i-1][1]+10-int(S[i-1]))
            elif j==1:
                dp[i][1]=min(dp[i-1][0]+int(S[i-1])+1,dp[i-1][1]+10-int(S[i-1])-1)

    print(dp[len(S)][0])

if __name__=="__main__":
    main()
