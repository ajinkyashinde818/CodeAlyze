import itertools
import math

d, g = map(int, input().split(" "))

all = set()
for x in range(0, d):
    all.add(x)

pl = list()
for i in range(0, d):
    p, c = map(int, input().split(" "))
    pl.append((i, p, c))

ans = 100000000
for n in range(0, d + 1):
    for select in itertools.combinations(pl, n):
        full_sum = 0
        full_count = 0
        full_list = set()

        for fp, fn, fc in select:
            full_sum += (fp + 1) * 100 * fn + fc
            full_count += fn
            full_list.add(fp)
        
        if full_sum >= g:
            ans = min(ans, full_count)
            # print("full: %s rest: None score: %d ans: %d" % (str(full_list), full_sum, ans))

        elif len(all - full_list) > 0:
            rest = max(all - full_list)
            rest_n, rest_p, rest_c = pl[rest]

            if g - full_sum <= (rest_n + 1) * 100 * (rest_p - 1):
                ans = min(ans, full_count + math.ceil((g - full_sum) / ((rest_n + 1) * 100)))
                # print("full: %s rest: %d score: %d ans: %d" % (str(full_list), rest_n, full_sum + rest_n * (rest_p - 1), ans))
        

print(ans)
