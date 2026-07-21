import math
n = int(input())


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


np = factorization(n)


def cont(x):
    a = 0
    c = 0
    while True:
        c += 1
        a += c

        if x >= a and x < a + c + 1:
            break

    return c


ans = 0
for i in np:
    if i[0] == 1:
        continue
    else:
        # print(cont(i[1]))
        ans += cont(i[1])
# print(np)
print(ans)
