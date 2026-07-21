import sys
n=int(input())
X=[int(i) for i in input().split()]
mod=10**9+7
n_max=n
F,FI=[0]*(n_max+1),[0]*(n_max+1)
F[0],FI[0]=1,1
for i in range(n_max):
  F[i+1]=(F[i]*(i+1))%mod
  FI[i+1]=pow(F[i+1],mod-2,mod)


ans=0
DP=[0]*n
DP[0]=1
DP[1]=1
ans=(ans+DP[1]*(X[1]-X[0])*F[n-1]*FI[0])%mod
for i in range(2,n):
  DP[i]=(F[i-1]+DP[i-1]*i)%mod
  ans=(ans+DP[i]*(X[i]-X[i-1])*F[n-1]*FI[i])%mod
print(ans)
