def fac(n):
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
if N==1:
    print(0)
else:
    ans=0
    for i in range(len(fac(N))):
        a=fac(N)[i][1]
        b=int((2*a+1/4)**0.5-1/2)
        ans+=b
    print(ans)
