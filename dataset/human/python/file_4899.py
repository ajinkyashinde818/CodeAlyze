MOD=10**9+7
def facinv(N):
    fac,finv,inv=[0]*(N+1),[0]*(N+1),[0]*(N+1)
    fac[0]=1;fac[1]=1;finv[0]=1;finv[1]=1;inv[1]=1
    for i in range(2,N+1):
        fac[i]=fac[i-1]*i%MOD
        inv[i]=MOD-inv[MOD%i]*(MOD//i)%MOD
        finv[i]=finv[i-1]*inv[i]%MOD
    return fac,finv,inv

N=int(input())
x=list(map(int,input().split()))

fac,finv,inv=facinv(N)

Inv=0
ans=0
for k in range(N-1):
    Inv=Inv+inv[k+1]
    res=Inv*(x[k+1]-x[k])
    ans=(ans+res)%MOD
print(ans*fac[N-1]%MOD)
