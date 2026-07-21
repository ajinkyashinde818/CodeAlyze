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

a = int(input())
b = factorization(a)
countation = 0
for i in range(len(b)):
    t = b[i][1]
    k = 1
    n = 1
    while t >= n:
        countation += 1
        k = k + 1
        n = k*(k+1)/2
if a != 1:
    print(countation)
else:
    print(0)
