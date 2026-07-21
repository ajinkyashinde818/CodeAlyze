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
a = factorization(N)

ans = []

for i in range(len(a)):
    tmp = 1
    while a[i][1] >= tmp and a[i][0] != 1:
        b = a[i][0]**tmp
        ans.append(b)
        a[i][1] -= tmp
        tmp += 1

print(len(ans))
