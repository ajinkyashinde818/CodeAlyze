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
pf = factorization(n)
cnt = 0
for p in pf:
    i = 1
    while True:
        if p[0] == 1:
            break
        n /= p[0]**i
        p[1] -= i
        cnt += 1
        i += 1
        if p[1] < i:
            break

print(cnt)
