import numpy as np
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr
N = int(input())
if N == 1:
    print(0)
else:
    b = factorization(N)
    count = 0
    for i in b:
        j = 1
        while(1):
            i -= j
            if i<0:
                break
            else:
                count += 1
                j += 1
    print(count)
