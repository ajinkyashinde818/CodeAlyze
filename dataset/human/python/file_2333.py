import math

D, G = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(D)]

digit = '0' + str(D) + 'b'
ans = float('INF')
for i in range(2**D):
    bit = list(str(format(i, digit)))
    p = 0
    cnt = 0
    last = -1
    for j in range(D):
        if bit[j] == '1':
            p += lst[j][1] + lst[j][0]*100*(j+1)
            cnt += lst[j][0]
        else:
            last = j
    r = G - p
    if r > 0 and last > -1:
        tmp = math.ceil(r/(100*(last+1)))
        if tmp < lst[last][0]:
            cnt += tmp
            ans = min(ans, cnt)
    elif r <= 0:
        ans = min(ans, cnt)

print(ans)
