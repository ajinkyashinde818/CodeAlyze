N = int(input())

if N == 1:
    print(0)
    exit()


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


count = 0

arr = factorization(N)

for a in arr:
    now = a[0]
    now_z = a[0]
    while True:
        if N % now_z == 0:
            count += 1
            N //= now_z
            now_z *= now
        else:
            break
print(count)
