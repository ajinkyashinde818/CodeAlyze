n=int(input())
n*=2
A=list(input())
mod=10**9+7
if A[0]=="W" or A[-1]=="W": print(0);exit()

A=[i=="B" for i in A]
LR=[""]*n
LR[0]="L"
for i  in range(n-1):
    LR[i+1]=LR[i] if A[i]!=A[i+1] else ["L","R"][LR[i]=="L"]
from collections import Counter
#print(LR)
C=Counter(LR)
if C["L"]!=C["R"]:print(0);exit()
if LR[-1]=="L": print(0);exit()

r=0
ans=1
n//=2
for s in range(2*n-1,-1,-1):
    if LR[s]=="R":
        r+=1
    else:
        ans*=r
        ans%=mod
        r-=1
for i in range(1,n+1):
    ans*=i
    ans%=mod
print(ans)
