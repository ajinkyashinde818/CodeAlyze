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
n=int(input())
p=factorization(n)
ans=0
if n==1:
    print(0)
    exit()
for i in range(len(p)):
    k=1
    while p[i][1]>0:
        p[i][1]-=k
        if p[i][1]>=0:
            ans+=1
            k+=1
        else:
            break
print(ans)
