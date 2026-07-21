from math import sqrt
n = int(input())
cnt = [0]*1000000
ans = 0
for i in range(2,int(sqrt(n))):
    if(n==1): break
    j = 1
    while n%i==0:
        n = n//i
        cnt[i-1]+=1
        if cnt[i-1]==j:
            ans+=1
            j+=1
            cnt[i-1]=0
if n!=1: ans+=1
print(ans)
