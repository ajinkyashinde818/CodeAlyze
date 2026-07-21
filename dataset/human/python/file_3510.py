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

    if not arr:
        arr.append([n, 1])

    return arr


N = int(input())
p = factorization(N)
count = 0
for x in p:
    if N == 1:
        break
    for j in range(1, x[1] + 1):
        if N % (x[0] ** j) == 0:
            N /= x[0] ** j
            count += 1
        else:
            break
print(count)
