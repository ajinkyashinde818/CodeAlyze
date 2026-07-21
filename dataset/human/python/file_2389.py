from math import ceil
from itertools import product

d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]

ans = 1000
for pat in product(["1", "0"], repeat=d):
    score = 0
    cnt = 0
    not_complete = 0
    for i, bl in enumerate(pat):
        if bl == "1":
            score += 100 * (i + 1) * pc[i][0] + pc[i][1]
            cnt += pc[i][0]
        else:
            not_complete = i

    if score < g:
        add = ceil((g - score) / (100 * (not_complete + 1)))
        if add < pc[not_complete][0]:
            cnt += add
        else:
            continue

    ans = min(ans, cnt)

print(ans)
