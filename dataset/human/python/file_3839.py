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

import math
def D():
    n = int(input())
    if n==1:
        print(0)
        return
    f = factorization(n)
    res = 0
    for i,j in f:
        res += math.floor(math.sqrt(2*j + 1/4) - 1/2)
    print(res)
D()
