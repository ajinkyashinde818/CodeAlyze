import math

d, g = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(d)]

ans = float('inf')
for i in range(2 ** d):
    sum = 0
    count = 0
    s = set(k for k in range(1, d + 1))
    for j in range(d):
        if (i >> j) & 1 == 1:
            sum += l[j][0] * (j + 1) * 100 + l[j][1]
            count += l[j][0]
            s.discard(j + 1)
    if sum < g:
        t = max(s)
        n = min(l[t - 1][0] - 1, math.ceil((g - sum) / (t * 100)))
        count += n
        sum += n * t * 100
    if sum >= g:
        ans = min(ans, count)
print(ans)
