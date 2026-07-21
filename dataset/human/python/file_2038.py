from collections import Counter
_=input()
s=list(Counter(list(input())).values())
mod=10**9+7
dp=[0]*len(s)
dp[0]=s[0]
for i in range(1,len(s)):
  dp[i]=dp[i-1]*(s[i]+1)+s[i]
print(dp[-1]%mod)
