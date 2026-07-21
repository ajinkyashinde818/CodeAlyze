from itertools import product
from math import ceil

d, g = map(int, input().split())
PC = [list(map(int, input().split())) for _ in range(d)]

min_count = 10 ** 10
for use in product(range(2), repeat=d):
    count = 0
    total = 0
    for i in range(d):
        if use[i]:
            total += (i + 1) * 100 * PC[i][0] + PC[i][1]
            count += PC[i][0]
    if total >= g:
        if count < min_count:
            min_count = count
    else:
        for i in range(d):
            if use[i]:
                continue
            if total + (i + 1) * 100 * (PC[i][0] - 1) >= g:
                tmp_count = count + ceil((g - total) // 100 / (i + 1))
                if tmp_count < min_count:
                    min_count = tmp_count

print(min_count)
