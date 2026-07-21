import math


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
a = factorization(n)
if a[0][0] == 1:
    print(0)
else:
    b = []
    c = [0,1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190]
    for i in range(len(a)):
        b.append(a[i][1])
    ans = 0
    for i in range(len(b)):
        for j in range(len(c)):
            if b[i] == c[j]:
                ans +=j
                break
            elif b[i] < c[j]:
                ans += j-1
                break
                
    print(ans)
