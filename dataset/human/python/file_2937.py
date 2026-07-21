def f(n):
    res = []
    for p in range(2, int(n**0.5)):
        k = 0
        while(n % p == 0):
            n //= p
            k += 1
        if k:
            res.append((p, k))
    if n != 1:
        res.append((n,1))
    return res


n = int(input())
ans = 0
r = f(n)
for p,k in r:
    tmp = 0
    cur = 1
    while(k>=cur):
        tmp += 1
        k -= cur
        cur += 1
    ans += tmp
print(ans)
