a=int(input())
def factorization(n):
    arr=[]
    temp=n
    for i in range(2,int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp//=i
            arr.append([i,cnt])
    if temp!=1:
        arr.append([temp,1])
    if arr==[]:
        arr.append([n,1])
    return arr
ww=factorization(a)
ans=0
if a==1:
    ans=0
else:
    for j in range(len(ww)):
        if 2>=ww[j][1]>=1:
            ans+=1
        if 5>=ww[j][1]>=3:
            ans+=2
        if 9>=ww[j][1]>=6:
            ans+=3 
        if 14>=ww[j][1]>=10:
            ans+=4
        if 20>=ww[j][1]>=15:
            ans+=5
        if 27>=ww[j][1]>=21:
            ans+=6
        if 35>=ww[j][1]>=28:
            ans+=7
        if ww[j][1]>=36:
            ans+=8
print(ans)
