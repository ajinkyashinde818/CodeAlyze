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


N = int(input())

if N == 1:
    print(0)
    exit()

prime = factorization(N)
count = 0
for i in range(len(prime)):
    num, e = prime[i]
    tmp = 1
    while True:
        e -= tmp
        if e >= 0:
            count += 1
        else:
            break
        tmp += 1
        
print(count)
