N = int(input())

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

A=factorization(N)
P=[row[1] for row in A]
if A[0][0]==1:
    print(0)
    exit()

ans=0

for i in range(len(P)):
    c=1
    while P[i]>=c:
        P[i]-=c
        c+=1
        ans+=1

print(ans)
