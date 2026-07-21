n=int(input())
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

a=factorization(n)

l=len(a)
ans=l
c=1
for i in range(l):
    a[i][1]-=1

while(c<100):
    c+=1
    for i in range(l):
        if a[i][1]>=c:
            a[i][1]-=c
            ans+=1
if n!=1 and n!=0:
    print(ans)
else:
    print(0)
