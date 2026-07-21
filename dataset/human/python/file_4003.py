N = int(input())


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


factors = factorization(N)
l = []
for factor in factors:
    for i in range(factor[1]):
        l.append(factor[0]**(i + 1))
l.sort()

ans = 0
for val in l:
    if N == 1:
        break

    if N % val == 0:
        N /= val
        ans += 1

print(ans)
