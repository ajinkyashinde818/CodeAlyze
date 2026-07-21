import math

D, G = list(map(int, input().split()))
pc = [list(map(int, input().split())) for _ in range(D)]

digit = '0'+str(D)+'b'
minimam = float("inf")

for i in range(2**D):
    pattern = list(str(format(i, digit)))
    point = 0
    count = 0
    tmp = -1
    for j in range(D):
        if pattern[j] == "1":
            p = pc[j][0]
            c = pc[j][1]
            point += p*100*(j+1)+c
            count += p
        else:
            tmp = j
    r = G - point
    if r > 0 and tmp > -1:
        countTmp = math.ceil(r/(100*(tmp+1)))
        # count += countTmp
        if countTmp < pc[tmp][0]:
            count += countTmp
        else:
            continue
    minimam = min(count, minimam)

print(minimam)
