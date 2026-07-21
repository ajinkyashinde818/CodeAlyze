def factorization(n):
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
    exit()

A=factorization(N)
ans=0
for a in A:
    n=a[1]#これが素因数の数
    i=1
    while n-i>=0 :
        ans+=1
        n-=i
        i+=1
print(ans)
