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

    return arr


n = int(input())
factors = factorization(n)

ans = 0
for factor, count in factors:
    use = 1
    possible = count
    while possible >= use:
        possible -= use
        use += 1
        ans += 1

print(ans)
