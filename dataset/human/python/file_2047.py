N=int(input())
S=input()
p=10**9+7

from collections import defaultdict
D=defaultdict(int)
num=0
ans=0
dp=[0]*N
dp[0]=2
D[S[0]]+=1
for i in range(1,N):
    s=S[i]
    if D[s]>=1:
        dp[i]=(dp[i-1]+dp[i-1]*pow(D[s]+1,p-2,p))%p
        #print(D[s])
        D[s]+=1
    else:
        dp[i]=dp[i-1]*2%p
        D[s]+=1
#print(dp)
print((dp[-1]-1)%p)
