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

n = int(input())

lis = factorization(n)

c = 0

for i in range(len(lis)):
    b = math.floor((lis[i][1]*2)**(1/2))
    if b*(b+1) > lis[i][1]*2:
        b = b - 1
    c = c + b
if n == 1:
    print(0)
else:
    print(c)
