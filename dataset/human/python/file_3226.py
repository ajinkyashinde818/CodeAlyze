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

factorization(24) 

n = int(input())
P = factorization(n)

Q = []
for i in range(len(P)):
    temp = 1
    while P[i][1] >= temp and P[i][0] != 1:
        t = P[i][0] ** temp
        Q.append(t)
        P[i][1] -= temp
        temp += 1

print(len(Q))
