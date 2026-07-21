N = int(input())


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

    # return arr
    cnt = 0
    for l in arr:
        factor = l[0]
        i = l[1]
        if factor != 1:
            div = 0
            while 1:
                div += 1
                i -= div
                if i >= 0:
                    cnt += 1
                else:
                    break

    return cnt


print(factorization(N))
