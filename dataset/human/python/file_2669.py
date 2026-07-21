import math

d, g = map(int, input().split())
ls = [[100 * (i + 1)] + list(map(int,
                                 input().split())) for i in range(d)][::-1]
l0 = [a * p + c for a, p, c in ls]

res = float('inf')
for index in range(2**d):
    cs = '{:b}'.format(index)
    cs = '0' * (d - len(cs)) + cs
    count = 0
    s = 0
    for i, c in enumerate(cs):
        if c == '1':
            count += ls[i][1]
            s += l0[i]
    if s < g:
        for i, c in enumerate(cs):
            if c == '0' and s + ls[i][0] * ls[i][1] >= g:
                n = math.ceil((g - s) / ls[i][0])
                count += n
                s += ls[i][0] * n
                break
    if s >= g:
        res = min(res, count)
print(res)
