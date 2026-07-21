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

f = factorization(int(input()))
c=0
for _,i in f:
    if _ == 1:
        print(0)
        exit()
    a=1
    while a*-~a//2 <= i:
        a+=1
    c+=~-a
print(c)
