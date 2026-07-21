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

H=[]
for j in range(10):
    H+=[j]*(j+1)

N=int(input())
S=0

if N!=1:
    L=factorization(N)
    S=0
    for (x,a) in L:
        S+=H[a]

print(S)
