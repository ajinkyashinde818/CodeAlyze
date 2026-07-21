m=int(input())
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

l=factorization(m)
ans=0
for i in range(len(l)):
    a=1
    while(l[i][1]>=a):
        ans+=1
        l[i][1]-=a
        a+=1
if m==1:
    print("0")
else:
    print(ans)
