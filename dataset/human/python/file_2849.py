def prime(n):
    a = 2
    res = []
    while (a * a <= n):
        if (n % a != 0):
            a += 1
            continue
        ex = 0

        while (n % a == 0):
            ex += 1
            n //= a

        res.append([a, ex])

    if (n != 1):
        res.append([n, 1])
    return res

n = int(input())
p = prime(n)

ans = 0
for i in p:
    count = 0
    for j in range(i[1]):
        ans += 1
        count += 1
        i[1] -= count
        if count >= i[1]:
            break

print(ans)
