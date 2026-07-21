def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5 // 1)) + 1):
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
if N == 1:
    print(0)
    exit()
L = factorization(N)
res = 0
for l in L:
    a = int(l[1])
    count = 1
    while True:
        if a >= count:
            a -= count
            res += 1
            count += 1
        else:
            break
print(res)
