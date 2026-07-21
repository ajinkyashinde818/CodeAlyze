import math
D, G = [int(x) for x in input().split()]
PC = [[int(x) for x in input().split()] for _ in range(D)]
ans = 100100
for i in range(2**D):
    cnt = 0
    point = 0
    for j in range(D):
        if (i >> j) & 1:
            cnt += PC[j][0]
            point += 100 * (j+1) * PC[j][0] + PC[j][1]
    if (point < G):
        rest = G-point
        for j in range(D)[::-1]:
            if (i >> j) & 1 == 0:
                if (rest < 100*(j+1)*PC[j][0]):
                    # 200点問題3問で500点
                    cnt += math.ceil(rest / (100*(j+1)))
                    break 
                else:
                    cnt = 100100
                    break
    ans = min(ans, cnt)
print(ans)
