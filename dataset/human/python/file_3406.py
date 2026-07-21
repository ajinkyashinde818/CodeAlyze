import math


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


def is_prime(n):
    for d in range(2, math.floor(math.sqrt(n)) + 1):
        if n % d == 0:
            return False
    return True


N = int(input())
if N == 1:
    print(0)
elif is_prime(N):
    print(1)
else:
    res = 0
    for _, count in factorization(N):
        if count <= 2:
            res += 1
        else:
            i = 1
            while count - i >= 0:
                count -= i
                i += 1
            res += (i - 1)
    print(res)
