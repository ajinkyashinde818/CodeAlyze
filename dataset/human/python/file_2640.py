import math
d, g = map(int, input().split())

p = [0] * d
a = [0] * d
for i in range(d):
    q, c = map(int, input().split())
    a[i] = q * (i + 1) * 100 + c
    p[i] = q

n = len(a)

min_val = sum(p)
for i in range(1 << n):
    score = 0
    val = 0
    k = -1
    for j in range(n):
        if i >> j & 1:
            score += a[j]
            val += p[j]
        else:
            k = j
    r = g - score
    if r > 0:
        if r >= a[k]:
            continue
        else:
            l = math.ceil(r / ((k + 1) * 100))
            if l >= p[k]:
                continue
            val += l
    min_val = min(min_val, val)
print(min_val)
