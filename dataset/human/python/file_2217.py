import math

D, G = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(D)]

ans = 100000000
for bit in range(1 << D):
    s = 0
    ans_ = 0
    li = 0
    for i in range(D):
        if bit & (1 << i):
            s += (i+1) * 100 * pc[i][0] + pc[i][1] 
            ans_ += pc[i][0]
        else:
          li = i  
    if s < G:
        lv = 100 * (li + 1)
        need = int(math.ceil((G - s) / lv))
        if pc[li][0] < need:
            continue
        ans_ += need
    ans = min(ans, ans_)

print(int(ans))
