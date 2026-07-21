def factorization(n):
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
ans=0
n=int(input())
L=factorization(n)
if n>1:
    for l in L:
        tmp=l
        for i in range(1,l+1):
            tmp-=i
            if tmp>=0:
                ans+=1
            if tmp<=0:
                break
print(ans)
