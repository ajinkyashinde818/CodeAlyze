N=int(input())
if N==1:
    print(0)
    exit()
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
nprime=factorization(N)
ans=0
for t in nprime:
    now=1
    count=0
    while t[1]>=now:
        t[1]-=now
        now+=1
        count+=1
    ans+=count
print(ans)
