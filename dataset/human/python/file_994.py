import sys
input = sys.stdin.readline

N=int(input())
S=list(input().strip())
mod=10**9+7

for i in range(2*N):
    if S[i]=="B":
        S[i]=0
    else:
        S[i]=1

    if i%2==1:
        S[i]=(S[i]+1)%2


ones=0
ANS=1

if S.count(1)!=S.count(0):
    print(0)
    sys.exit()

for i in range(2*N-1,-1,-1):
    if S[i]==1:
        ones+=1

    else:
        ANS=ANS*ones%mod
        ones-=1


for i in range(1,N+1):
    ANS=ANS*i%mod


print(ANS)
