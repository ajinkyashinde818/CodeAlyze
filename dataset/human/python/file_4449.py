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
F = factorization(n)
counter = 0
for a in range(len(F)):
    B = int((-1+(1+8*F[a][1])**0.5)/2)
    counter += B

if F[0][0] == 1:
    print(0)
else:
    print(counter)
