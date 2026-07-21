A = int(input())

import sys

if A ==1:
    print(0)
    sys.exit()

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

def counting(x):
    i = 1
    result = 0
    while i<=x:
        result +=1
        x -=i
        i +=1
    return result

arr = factorization(A)

result = 0
for i in range(len(arr)):
    result += counting(arr[i])

print(result)
