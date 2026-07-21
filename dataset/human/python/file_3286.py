import sys
n=int(input())
if n==1:
    print(0)
    sys.exit()
def f(n):
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
tmp=f(n)
ans=0
for i in tmp:
    dd=i[1]
    tt=1
    while dd>0:
        if dd-tt>=0:
            dd-=tt
            tt+=1
            ans+=1
        else:
            break
print(ans)
