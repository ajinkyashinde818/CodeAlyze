import math

d, g = [int(_) for _ in input().split(' ')]
p = []
c = []
for _ in range(d):
    temp = [int(_) for _ in input().split(' ')]
    p.append(temp[0])
    c.append(temp[1])

answer = 1001
for i in range(2 ** d):
    sc = 0
    pr = 0
    for j in range(d, 0, -1):
        if i & (1 << (j - 1)) > 0:
            sc += j * 100 * p[j - 1] + c[j - 1]
            pr += p[j - 1]
    for j in range(d, 0, -1):
        if sc < g and i & (1 << (j - 1)) == 0:
            temp = min(math.ceil((g - sc) / (j * 100)), p[j - 1] - 1)
            sc += temp * (j * 100)
            pr += temp
    if sc >= g and pr < answer:
        answer = pr

print(answer)
