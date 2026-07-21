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

N = int(input())
fact = factorization(N)
l = len(fact)
ans = 0
if N == 1:
    print(0)
else:
    for i in range(l):
        n = (math.sqrt(8*fact[i][1]+1) -1)//2
        ans += int(n)
    print(ans)
