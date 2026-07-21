from math import ceil
ans = float('inf')
D, G = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(D)]
for i in range(1 << D):
    point = 0
    count = 0
    tmp = 0
    for j in range(D):
        if ((i >> j) & 1) == 0:
            if (100 * j + 100) * p[j][0] + p[j][1]:
                tmp = j
        else:
            point += (100 * j + 100) * p[j][0] + p[j][1]
            count += p[j][0]
    if G - point > 100 * (tmp + 1) * p[tmp][0]:
        continue
    count += max(0, ceil((G - point) / (100 * (tmp + 1))))
    ans = min(ans, count)
print(ans)
