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
A=factorization(N)
B=len(A)
k=0

for i in range(B):
    a=1
    while A[i][1]>=a*(a+1)/2:
        a+=1
    k=k+a-1
if N==1:
    print(0)
else:
    print(k)
