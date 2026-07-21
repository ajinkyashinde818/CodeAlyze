import itertools,sys
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
R,G,B,N = LI()
dp = [0]*(N+1)
dp[0] = 1
for x,i in itertools.product([R,G,B],range(N+1)):
    if i-x>=0:
        dp[i] += dp[i-x]
print(dp[-1])
