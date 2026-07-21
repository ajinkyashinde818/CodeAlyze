def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


N = int(input())
fact = factorization(N)
ans = 0
for f in fact:
    if f[0] >= 2:
        remain = f[1]
        tmp = 1
        while True:
            remain -= tmp
            if remain >= 0:
                ans += 1
            else:
                break
            tmp += 1
print(ans)
