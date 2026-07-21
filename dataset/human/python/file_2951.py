def factorize(n):
    x = 2
    f = []
    while x**2 <= n:
        c = 0
        if n % x != 0:
            x += 1
            continue
        else:
            while n % x == 0:
                n //= x
                c += 1
            f.append([x, c])
        x += 1

    if n > 1:
        f.append([n, 1])
    return f

n = int(input())
f = factorize(n)
ans = 0
for el in f:
    m = el[1]
    i = 1
    while True:
        if i*(i+1)//2 > m:
            ans += i-1
            break
        i += 1

print(ans)
