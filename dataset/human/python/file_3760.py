import sys

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
    sys.exit()

A=factorization(N)

numlist=range(2,50)
sinsa=1
ans=0
for i in range(len(A)):
    beki=A[i][1]
    sosu=A[i][0]
    sinsa=1
    for j in range(1,beki+1):
        N=N/(sosu**j)
        ans+=1
        sinsa=sinsa+j+1
        if sinsa>beki:
            sinsa=1
            break
print(ans)
