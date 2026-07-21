import sys
mod=10**9+7
n=int(input())
s=input()

count=0
ans=1
for i in range(2*n):
    if s[i]=="B": p=1
    else: p=0
    if (count+p)%2==0:
        ans=ans*count%mod
        count-=1
    else: count+=1
    if count<0: print(0);sys.exit()
if count!=0: print(0);sys.exit()
for i in range(1,n+1):
    ans=ans*i%mod
print(ans)
