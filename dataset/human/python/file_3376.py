N=int(input())

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

def calc(n):
    ans=0
    tmp=0
    c=1
    while(1):
        tmp+=c
        if tmp>n:
            break
        ans=c
        c+=1
    return ans

L=factorization(N)
if N==1:
    print(0)
    exit()
ans=0
for i in range(len(L)):
    val=L[i][0]
    cnt=L[i][1]
    ans+=calc(cnt)

print(ans)
