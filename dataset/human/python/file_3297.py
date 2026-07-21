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


arr = factorization(int(input()))
res = 0

if arr[0][0] != 1:
    
    for i in arr:
        cnt = 1
        while(i[1]>=cnt):
            i[1] -= cnt
            cnt += 1
            res +=1
            
print(res)
