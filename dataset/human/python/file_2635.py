from itertools import product
from math import ceil

d, g = map(int, input().split())
pc = []
for i in range(d):
    pc.append(list(map(int, input().split())))

ans = 10 ** 10
for e in product((0, 1), repeat=d):
    total_cnt = 0
    score = 0
    odd_idx = 0
    for j in range(d):
        if e[j] == 1:
            cnt = pc[j][0]
            bonus = pc[j][1]
            score += cnt * ((j + 1) * 100) + bonus
            total_cnt += cnt
        else:
            odd_idx = j

    if g <= score:
        ans = min(ans, total_cnt)
    else:
        odd_point = (odd_idx + 1) * 100
        odd_cnt = pc[odd_idx][0] - 1
        if g <= score + (odd_cnt * odd_point):
            total_cnt += ceil((g - score) / odd_point)
            ans = min(ans, total_cnt)
print(ans)
