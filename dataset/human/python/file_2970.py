def factorize(n):
    fct = []
    b = 2
    e = 0
    while b * b <= n:
        while n % b == 0:
            n //= b
            e += 1
        if e > 0:
            fct.append((b, e))
        b += 1
        e = 0
    if n > 1:
        fct.append((n, 1))
    return fct


n = int(input())

fct = factorize(n)

ans = 0
for i in fct:
    nokori = i[1]
    count = 1
    while nokori >= count:
        nokori -= count
        count += 1
        ans += 1

print(ans)
