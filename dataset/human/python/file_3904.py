def fa(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr
N=int(input())
soi=fa(N)
ans=0
for n in range(len(soi)):
    if soi[n][1]<=2:
        ans+=1
    elif soi[n][1]<=5:
        ans+=2
    elif soi[n][1]<=9:
        ans+=3
    elif soi[n][1]<=14:
        ans+=4
    elif soi[n][1]<=20:
        ans+=5
    elif soi[n][1]<=27:
        ans+=6
    elif soi[n][1]<=35:
        ans+=7
    elif soi[n][1]<=44:
        ans+=8
    elif soi[n][1]<=54:
        ans+=9
if N==1:
    ans=0
print(ans)
