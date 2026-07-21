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
ans=0
for p,c in factorization(N):
    if p==1:
        continue
    n=1

    while n*(n+1)<=2*c:
        n+=1
    n-=1
    ans+=n

print(ans)
