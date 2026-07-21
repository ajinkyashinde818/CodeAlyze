def prime_factorize(n):
    a = []
    tmp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            a.append([i, cnt])
    if tmp != 1:
        a.append([tmp, 1])
    if not len(a) and n != 1:
        a.append([n, 1])
    return a


N = int(input())

ans = prime_factorize(N)
count = 0
for ls in ans:
    target = ls[1]
    tmp = 1
    while True:
        if target - tmp >= 0:
            target = target - tmp
            tmp += 1
            count += 1
        else:
            break
print(count)
