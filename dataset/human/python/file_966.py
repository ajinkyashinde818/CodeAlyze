from itertools import accumulate
mod=1000000007
n=int(input())
S=input()
Flag=[0]*(2*n)
for i,s in enumerate(S):
    if i%2:
        Flag[i]=int(s=='W')
    else:
        Flag[i]=int(s=='B')
Acc=list(accumulate(Flag))
if Acc[-1]!=n or Flag[-1]==1:
    print(0)
    exit()
ans=1
cnt=0
for i,f in enumerate(Flag):
    if f==0:
        tmp=Acc[i]-cnt
        ans*=tmp
        ans%=mod
        cnt+=1
for i in range(1,n+1):
    ans*=i
    ans%=mod
print(ans)
