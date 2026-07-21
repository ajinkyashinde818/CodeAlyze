N=int(input())
x=[int(i) for i in input().split()]
d=[x[i+1]-x[i] for i in range(N-1)]
ans=0
tmp=0
N1fact=1
mod=10**9+7
def inv(x):
    return pow(x,mod-2,mod)
for i in range(1,N):
    N1fact=(i*N1fact)%mod
for k in range(1,N):
    tmp+=inv(k)
    tmp%=mod
    a1=tmp
    a2=(d[k-1]*N1fact)%mod
    #print(a1,a2)
    ans+=(a1*a2)%mod
    ans%=mod
print(ans)
#print(N1fact)
#print((ans*N1fact)%mod)
