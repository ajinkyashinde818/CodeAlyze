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


def calcN(num):
    if num >= 45:
        return 9
    elif num >= 36:
        return 8
    elif num >= 28:
        return 7
    elif num >= 21:
        return 6
    elif num >= 15:
        return 5
    elif num >= 10:
        return 4
    elif num >= 6:
        return 3
    elif num >= 3:
        return 2
    elif num >= 1:
        return 1
    

A = int(input())
if A == 1:
    print(0)
else:
    insuu =  factorization(A)
    ret = 0
    for i in insuu:
        ret += calcN(i[1])
    print(ret)
