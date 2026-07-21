n=int(input())
a=[int(k) for k in input().strip().split(" ")]
ai=a[::-1]
res=0

mod=10**9+7
fact=[1]
for i in range(1,100000):
    fact+=[(i*fact[-1]%mod)]

sa=[0]
for k in a:
    sa+=[(sa[-1]+k)%mod]

def ssum(l,r):
    return (sa[r+1]-sa[l])%mod

b=[[0 for i in range(2)] for j in range(n-1)]
b[0][0]=fact[n-1]
b[0][1]=(b[0][0]*pow(2,mod-2,mod))%mod
res+=(b[0][0]*(a[-1]-a[-2]))%mod
if n>2:
    res+=(b[0][1]*(ssum(1,n-2)-ssum(0,n-3)))%mod
for j in range(2,n):
    b[j-1][0]=(b[j-2][0]*(j-1) * pow(j,mod-2,mod))%mod
    res+=(b[j-1][0]*(a[-1]-a[-j-1]))%mod
    if j<n-1:
        b[j-1][1]=(b[j-2][1]*(j-1) * pow(j+1,mod-2,mod))%mod
        res+=(b[j-1][1]*(ssum(j,n-2)-ssum(0,n-j-2)))%mod

print(res%mod)
