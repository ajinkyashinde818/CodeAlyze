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


fcl = factorization(N)

result = 0
count = len(fcl)

for i in range(count):
    num = 1
    while fcl[i][1] >= num:
        fcl[i][1] = fcl[i][1] - num
        num += 1
        if fcl[i][0] > 1:
            result += 1
print(result)
