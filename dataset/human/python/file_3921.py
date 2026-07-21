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


n = int(input())
cnt = 0
z_list = []
f = factorization(n)
for fact in f:
    for j in range(1, fact[1] + 1):
        z = fact[0] ** j
        if z < 2:
            print(0)
            exit()
        if str(z) not in z_list:
            if n % z == 0:
                n = n // z
                cnt += 1
print(cnt)
