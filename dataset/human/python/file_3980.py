import math
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
if(N==1):
    print(0)
else:
    prime_factor=factorization(N) 
    nrow=len(prime_factor)
    n=0
    for i in range(nrow):
        order=prime_factor[i][1]
        n+=math.floor((-1.0+math.sqrt(1.0+8.0*order))/2.0)
    print(n)
