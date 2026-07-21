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
    f = factorization(n)
    result = 0
    for each in f:
        shisu = each[1]
        counter = 1
        while shisu >= counter and shisu >= 0:
            shisu -= counter
            counter += 1
            result += 1
    print(result)
