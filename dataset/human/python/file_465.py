import sys
sys.setrecursionlimit(10**6)

n = int(input())
A = list(map(int, input().split()))
INF = 10**9

dp = [[0]*2 for _ in range(n+1)] # dp[i][0]がiを選んで反転させない場合の最大値, dp[i][1]がiを選んで反転させた場合の最大値

dp[0][0] = 0 
dp[0][1] = -INF

for i in range(1,n+1):
    dp[i][0] = max(dp[i-1][0]+A[i-1], dp[i-1][1]-A[i-1]) # iを選んで反転させない時、 i-1を選んで反転させていなかったらiはそのままで、i-1を反転させていたらiは反転する
    dp[i][1] = max(dp[i-1][0]-A[i-1], dp[i-1][1]+A[i-1]) # iを選んで反転させる時、i-1を選んで反転させていなかったらiは反転していて、i-1を反転させていたらiはそのまま

print(dp[n][0]) # nを選ぶことはできない（n+1が存在しない）ため、答えはdp[n][0]
