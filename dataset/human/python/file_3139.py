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


def calc(num):
    ret = 0
    left = num
    count = 1
    while True:
        if left >= count:
            ret = count
            left -= count
            count += 1
        else:
            break
    return ret


n = int(input())

ret = factorization(n)

val = 0

for tmp, num in ret:
    if tmp == 1:
        continue
    val += calc(num)

print(val)
