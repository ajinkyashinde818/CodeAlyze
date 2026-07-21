import math
d, g = map(int, input().split())
p = []
c = []
for _ in range(d):
    tp, tc = map(int, input().split())
    p.append(tp)
    c.append(tc)

ans = 1000
for i in range(2**d):
    score = 0
    num = 0
    r = -1
    for j in range(d):
        if i>>j & 1:
            score += 100 * (j+1) * p[j] + c[j]
            num += p[j]
        else:
            r = j
    if score < g:
        tmp = math.ceil((g-score) / (100*(r+1)))
        if tmp >= p[r]:
            continue
        num += tmp
    ans = min(ans, num)
print(ans)
