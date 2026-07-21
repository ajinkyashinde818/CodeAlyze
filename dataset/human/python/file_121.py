from math import ceil

r, g, b, n = map(int, input().split())
cnt = 0
for i in range(ceil(n / r) + 1):
    for j in range(ceil(n / g) + 1):
        if i * r + j * g > n:
            break
        if i * r + j * g == n:
            cnt += 1
            continue
        else:
            tmp = n - (i * r + j * g)
            if tmp % b == 0:
                cnt += 1
print(cnt)
