from itertools import product
import math

d, g = map(int, input().split())
ps = []
cs = []

for i in range(d):
    pi, ci = map(int, input().split())
    ps.append(pi)
    cs.append(ci)

min_count = 10000000
for pro in product([0,1,2], repeat=d):
    if len([_ for _ in pro if _ == 2]) <= 1:
        tmp_count = 0
        tmp_total = 0
        for i in range(len(pro)):
            if pro[i] == 1:
                tmp_count += ps[i]
                tmp_total += ps[i] * (i+1) * 100 + cs[i]
        if tmp_total >= g:
            min_count = min(min_count, tmp_count)
            continue
        elif 2 in pro and ps[pro.index(2)] * (pro.index(2)+1) * 100 >= g-tmp_total:
            tmp_count += -(-(g-tmp_total) // ((pro.index(2)+1) * 100))
            tmp_total += tmp_count * (pro.index(2)+1) * 100
            min_count = min(min_count, tmp_count)
            continue

print(min_count)
