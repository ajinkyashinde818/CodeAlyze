def factorization(n):
    """
    nを素因数分解
    2以上の整数n => [[素因数, 指数], ...]の2次元リスト
    """
    arr = []
    temp = n
    for i in range(2, int(-(-(n ** 0.5) // 1)) + 1):
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


N = int(input())
fact_li = factorization(N)
ans = 0
for t in fact_li:
    if t[0] == 1:
        continue
    tmp = t[1]
    for i in range(1, tmp + 1):
        if tmp >= i:
            ans += 1
            tmp -= i
        else:
            break

print(ans)
