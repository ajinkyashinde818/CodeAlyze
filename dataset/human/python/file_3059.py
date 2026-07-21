import collections
def pf(N):
    res = []
    x = N
    y = 2
    while y*y <= x:
        while x % y == 0:
            res.append(y)
            x //= y
        y += 1
    if x > 1:
        res.append(x)
    return res

cnt = collections.Counter(pf(int(input())))
ans = 0
for x in cnt:
    tmp = 1
    while cnt[x] > 0:
        cnt[x] -= tmp
        if cnt[x] < 0:
            break
        tmp += 1
        ans += 1
print(ans)
