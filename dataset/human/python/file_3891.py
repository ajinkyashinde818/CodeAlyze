import bisect
n = int(input())
def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(int(i))
        i += 1
    if n > 1: table.append(int(n))
    table.sort()
    return table
ans = 0
d = prime_decomposition(n)
for i in list(set(d)):
    index_l = bisect.bisect_left(d, i)
    index_r = bisect.bisect_right(d, i)
    i = 1
    res = index_r-index_l
    while True:
        res -= i
        ans += 1
        if res == 0:
            break
        if res < 0:
            ans -= 1
            break
        i += 1
print(ans)
