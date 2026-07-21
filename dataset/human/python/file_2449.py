def solve():
    d = 0
    c = 0
    for i in range(D):
        d += p[i][0]
    dp = [[0]*(d+1) for i in range(D)]
    for i in range(D):
        for j in range(p[i][0]+1):
            if i == 0:
                if j == p[i][0]:
                    dp[i][j] += p[i][1]
                dp[i][j] += 100*j
            else:
                for k in range(c+1):
                    if j == p[i][0]:
                        dp[i][k+j]=max(dp[i][k+j],dp[i-1][k]+100*j*(i+1)+p[i][1])
                    else:
                        dp[i][k+j]=max(dp[i][k+j],dp[i-1][k]+100*j*(i+1))
        c += p[i][0]
    for i in range(d+1):
        if dp[D-1][i]>=G:
            print(i)
            break    
    
if __name__=="__main__":
    D,G = list(map(int, input().split()))
    p = [list(map(int, input().split())) for _ in range(D)]
    solve()
