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
if n == 1:
    print(0)
    
else:
    a = factorization(n)
    result = 0
    
    for i in range(len(a)):
        j = 1
        while(1):
            a[i][1] -= j
            if a[i][1] < 0:
                break
            result += 1
            j += 1
            
    print(result)
