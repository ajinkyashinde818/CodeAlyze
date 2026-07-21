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
    
fact = factorization(N)

import math

ans = 0

if N!= 1:
    
    for f in fact:
        X = f[1]
        n = math.ceil(math.sqrt(2*X)-1)
        if n * (n+1) > 2* X:
            n = n-1
            
        ans += n
        
print(ans)
