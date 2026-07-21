def factor(n):
    table = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                n //= i
                cnt += 1
            table.append((i, cnt))
        i += 1
    if n > 1:
        table.append((n, 1))
    return table

N = int(input())

F = factor(N)

ans = 0
for _, e in F:
    x = 1
    while not (x * (x + 1) <= 2 * e < (x + 1) * (x + 2)):
        x += 1
    ans += x

print(ans)
