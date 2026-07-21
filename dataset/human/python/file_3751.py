import math
n = int(input())

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

if n == 1:
    print(0)
else:

    l = factorization(n)



    if all(l[i][1] == 1 for i in range(len(l))):
        ans = len(l)
    else:
        ans = 0
        for i in range(len(l)):
            if l[i][1] == 1:
                ans += 1
            else:
                ans += int(( -1 + math.sqrt(1 + 8 * l[i][1]) ) / 2)
    print(ans)
