k,s=map(int,input().split())
dp=[0]*(3*k+4)
dp[0]=1
dp[k+1]=-3
dp[2*k+2]=3
dp[-1]=-1
from itertools import accumulate
dp=list(accumulate(list(accumulate(list(accumulate(dp))))))
print(dp[s])
