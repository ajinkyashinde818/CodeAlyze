import sys
N=int(input())
S=list(input())
mod=10**9+7
data=[0]*2*N
if S[0]=="W":
    print(0)
    sys.exit()
data[0]=-1
for i in range(1,2*N):
    if S[i]==S[i-1]:
        data[i]=-data[i-1]
    else:
        data[i]=data[i-1]
if data[-1]==-1:
    print(0)
    sys.exit()
lst=[0]*2*N
lst[-1]=data[-1]
for i in range(2*N-2,-1,-1):
    lst[i]=lst[i+1]+data[i]
ans=1
for i in range(2*N-1,-1,-1):
    if data[i]==-1:
        ans=ans*(lst[i]+1)%mod
count=0
for i in range(2*N):
    if data[i]==1:
        count+=1
if count!=N:
    print(0)
    sys.exit()
for i in range(1,N+1):
    ans=ans*i%mod
print(ans)
