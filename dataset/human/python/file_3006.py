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


n = int(input())
if n == 1:
    print(0)
    exit()
z = factorization(n)
cnt = 0
for item in z:
    p = item[0]
    e = item[1]
    num = 1
    while e >= num:
        e -= num
        cnt += 1
        num += 1

print(cnt)
