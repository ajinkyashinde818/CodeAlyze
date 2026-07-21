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
ans = 0

A = factorization(N)

for x in A:
    e = x[1]
    for y in range(1,N):
        if e >= y:
            e -= y
            ans += 1
        else:
            break

print(ans)
