def fac(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)
    return arr

n=int(input())
li=fac(n)

ans=0
y=0
if n==1:
    ans=0
else:
    for x in range(1,1000):
        y=y+x
        ans=ans+len([i for i in li if i >= y])
        if len([i for i in li if i >= y])==0:
            break
print(ans)
