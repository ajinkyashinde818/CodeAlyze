def factorize(n):
    res = []
    i = 2
    while i * i <= n:
        cnt = 0
        while n % i == 0:
            cnt += 1
            n //= i
        if cnt > 0:
            res.append([i, cnt])
        i += 1
    if n != 1:
        res.append([n, 1])
    return res

n = int(input())
nlist = factorize(n)
ans = 0
for k, v in nlist:
    i = 1
    while v >= i:
        v -= i
        i += 1
    ans += i-1
print(ans)
