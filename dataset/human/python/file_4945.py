N = int(input())
X = list(map(int,input().split()))
S = []
dp = [1]
mod = 10**9+7
for i in range(N):
    t = i+1
    dp.append(dp[i]*t%mod)
def power(a,b):
    if b == 0:
        return 1
    if b % 2 == 0:
        d = power(a,b//2)
        return d*d%mod
    elif b % 2 == 1:
        return a*power(a,b-1)%mod
W = []
for i in range(1,N):
    y = dp[N-1]*power(i,mod-2)%mod
    W.append(y)
ans = 0
for i in range(N-1):
    x = X[i]
    S.append(X[N-1]-x)
ans = 0
for i in range(N-1):
    x = S[i]
    t = i + 1
    ans += W[i]*x%mod
print(ans%mod)
