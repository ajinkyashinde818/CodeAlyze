import math
n=int(input())
X=[0]*(10**6+1)
if n==1:
    ans=0
else:
    p=int(math.sqrt(n))
    for i in range(2,int(math.sqrt(n)+1)):
        cnt=0
        while n%i==0:
            n//=i
            cnt+=1
        X[i]=cnt
    ans=0
    for x in X:
        if x>=55:
            ans+=10
        elif x>=45:
            ans+=9
        elif x>=36:
            ans+=8
        elif x>=28:
            ans+=7
        elif x>=21:
            ans+=6
        elif x>=15:
            ans+=5
        elif x>=10:
            ans+=4
        elif x>=6:
            ans+=3
        elif x>=3:
            ans+=2
        elif x>=1:
            ans+=1

    if n!=1:
        ans+=1

print(ans)
