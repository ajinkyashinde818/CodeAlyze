import math
N=int(input())
L=list(map(int,input().split()))
a=0
mod=10**9+7
s=math.factorial(N-1)
ans=[s%mod]
for i in range(2,N):
  ans.append((ans[-1]+(ans[0]*pow(i,-1,mod)))%mod)
ans2=0
for i in range(N-1):
  ans2+=((L[i+1]-L[i])*ans[i])%mod
print(ans2%mod)
