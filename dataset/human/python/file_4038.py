def fctr1(n):
    f = {}
    c = 0
    r = int(n**0.5)
    for i in range(2, r+2):
        while n % i == 0:
            c += 1
            n = n//i
        if c != 0:
            f[i] = c
            c = 0
    if n != 1:
        f[n] = 1
    return f


N = int(input())
p = fctr1(N)
ans = 0
for k, v in p.items():
    c = 0
    while (v-c-1) >= 0:
        c += 1
        v -= c
    ans += c

print(ans)
