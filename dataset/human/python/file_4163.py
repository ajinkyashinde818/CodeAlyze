def factorization(n):#素因数分解
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
fac = factorization(N)
cnt = 0

if N == 1:
    print(0)
    exit()

for i in range(len(fac)):
    e = 1
    while fac[i][1]-e >= 0:
        fac[i][1] -= e
        e += 1
        cnt += 1 
print(cnt)
