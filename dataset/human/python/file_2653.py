from math import ceil
d,g = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(d)]

ans = float('INF')
inf = float('INF')
for i in range(2**d):
    tmp = 0
    cnt = 0
    for j in range(d):
        p,c = pc[j]
        if i & (1 << j):
            tmp += p * (j+1) * 100 + c
            cnt += p
    if g <= tmp and cnt < ans:
        ans = cnt
    if g > tmp:
        tmp_cnt = inf 
        tmp_ = 0
        gg = (g - tmp) / 100
        for j in range(d):
            p,c = pc[j]
            if i & (1 << j):
                continue
            if ceil(gg / (j+1)) < min(p,tmp_cnt):
                cc = ceil(gg / (j+1))
                tmp_ = cc * (j+1) * 100
                tmp_cnt = cc
            elif gg - c / 100 <= p * (j+1) and p < tmp_cnt:
                tmp_ = p * (j+1) * 100 + c
                tmp_cnt = p
        if g <= tmp + tmp_ and cnt + tmp_cnt < ans:
            ans = cnt + tmp_cnt

print(ans)
