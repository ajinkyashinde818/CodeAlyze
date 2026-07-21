inp = list(map(int, input().split()))


def factorize(n):
    arr = []
    tmp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            arr.append([i, cnt])

    if tmp != 1:
        arr.append((tmp, 1))

    if not arr and n != 1:
        arr.append((n, 1))

    return arr


re = 0

for _, c in factorize(inp[0]):
    tmp1 = c
    tmp2 = 1
    while tmp1 >= tmp2:
        re += 1
        tmp1 -= tmp2
        tmp2 += 1


print(re)
