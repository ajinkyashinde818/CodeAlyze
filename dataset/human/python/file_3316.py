import math
import os
ans = 0
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
n = int(input())
arr = factorization(n)
if n==1:
    print(0)
    exit()

for i in range(len(arr)):
    arfa = arr[i][1]
    ans += math.floor((-1+math.sqrt(1+8*arfa))/2)
print(ans)
