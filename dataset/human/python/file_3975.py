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


n=int(input())
arr=factorization(n)

z=0    
if n!=1:
    for i in range(len(arr)):
        k=0
        for j in range(1,100000):
            k+=j
            z+=1
            if k+j+1>arr[i][1]:
                break

print(z)
