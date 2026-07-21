import sys
 
mod=10**9+7
N=input()
X=map(int, sys.stdin.readline().split())
L=map(lambda x: pow(x,mod-2,mod), range(1,N))
 
L_RUISEKI=[]
 
for i,x in enumerate(L):
    if i==0: L_RUISEKI.append(x)
    else: L_RUISEKI.append(L_RUISEKI[-1]+x)
 
ans=0
for i in range(N-1):
    value=X[i+1]-X[i]
    ans+=value*L_RUISEKI[i]
 
 
fact=[1]
fact_tmp = 1
for i in range(1, N+1):
    fact_tmp *= i
    fact_tmp %= mod
    fact.append(fact_tmp)
 
print ans*fact[N-1]%mod
