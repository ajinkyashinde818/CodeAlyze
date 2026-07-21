import sys
input = sys.stdin.readline

N=int(input())
X=list(map(int,input().split()))

mod=10**9+7

D=[]

for i in range(1,N):
    D.append(X[i]-X[i-1])

FACT=[1]
for i in range(1,2*10**5+1):
    FACT.append(FACT[-1]*i%mod)

INV2=pow(2,mod-2,mod)

K=[1]

for i in range(2,10**5+3):
    K.append(K[-1]+pow(i,mod-2,mod))


ANS=0

for i in range(N-1):
    ANS=(ANS+K[i]*D[i])%mod
    
print(ANS*FACT[N-1]%mod)
