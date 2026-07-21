import math
d, g = [int(item) for item in input().split()]
pc = [[int(item) for item in input().split()] for _ in range(d)]

ans = 10**5
for i in range(2**d):
    count = 0
    score = 0
    for j in range(d):
        if i >> j & 1:
            count += pc[j][0]
            score += pc[j][1] + pc[j][0] * (j+1) * 100
    if score >= g:
        ans = min(ans, count)
        continue
    lest_i = d-1 
    while i >> lest_i & 1:
        lest_i -= 1

    lest_num = math.ceil((g - score) / ((lest_i + 1) * 100))
    if lest_num < pc[lest_i][0]:
        count += lest_num
        ans = min(ans, count)
print(ans)
