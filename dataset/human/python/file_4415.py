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

A = factorization(N)
ans = 0
for a, b in A:
    if a == 1:
        continue
    cnt = b
    for i in range(1, b+1):
        if cnt < i:
            break
        cnt -= i
        ans += 1
print(ans)
