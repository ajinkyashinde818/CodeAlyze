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


def sum_n(n):
    return int(n*(1+n)/2)


N = int(input())

if (N == 1):
    print(0)
    exit(0)

fac = factorization(N)


count = 0

for i in range(len(fac)):
    j = 0
    while (True):
        j += 1
        if (sum_n(j) == fac[i][1]):
            break
        elif (sum_n(j) > fac[i][1]):
            j = j - 1
            break

    count += j

print(count)
