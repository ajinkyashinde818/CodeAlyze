N = int(input())


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
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


bunkai = factorization(N)
count = 0

prime_flag = False
for x in bunkai:
    if x[0] == 1:
        prime_flag = True
        break
    else:
        check = x[1]
        current = 2
        while True:
            check -= current
            if check > 0:
                current += 1
            else:
                break
        count += current - 1
if prime_flag:
    print(0)
else:
    print(count)
