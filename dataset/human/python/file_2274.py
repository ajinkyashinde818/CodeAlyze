from itertools import product

d, g = [int(i) for i in input().split()]
p = []
c = []
for _ in range(d):
    ipt = [int(i) for i in input().split()]
    p.append(ipt[0])
    c.append(ipt[1])

res = 100*10+1
for solved in product((0, 1),repeat=d):
    cnt = score = max_i = 0
    for i, prob in enumerate(solved):
        if prob:
            cnt += p[i]
            score += p[i] * 100 * (i+1) + c[i]
        else:
            max_i = i

    if score < g:
        for _ in range(p[max_i]):
            cnt += 1
            score += 100 * (max_i+1)
            if score >= g:
                break

    if score >= g and cnt < res:
        res = cnt

print(res)
