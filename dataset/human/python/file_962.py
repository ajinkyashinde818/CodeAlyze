from collections import Counter
N=int(input())
mod=10**9+7
factl=[1]
for i in range(1,N+1):
    factl.append(factl[-1]*i%mod)
invl=[pow(factl[-1],mod-2,mod)]
for i in range(N,0,-1):
    invl.append(invl[-1]*i%mod)
invl.reverse()
def Comb(a,b):
    return factl[a]*invl[a-b]*invl[b]

S=list(input())
RS=S[::-1]
L=[0]*2*N
r=0
for i in range(N):
    if r%2==0 and S[i]=='B':
        L[i]=1
        r+=1
    elif r%2==1 and S[i]=='W':
        L[i]=1
        r+=1
    else:
        r-=1
r=0
L=L[::-1]
S=S[::-1]
for i in range(N):
    if r%2==0 and S[i]=='B':
        r+=1
    elif r%2==1 and S[i]=='W':
        r+=1
    else:
        r-=1
        L[i]=1
L=L[::-1]
Cnt=Counter(L)
if Cnt[0]!=Cnt[1]:
    print(0)
    exit()
l=0
ans=1
for i in range(2*N):
    if L[i]==1:
        l+=1
    else:
        ans*=l
        ans%=mod
        l-=1
ans=ans*factl[N]%mod
print(ans)
