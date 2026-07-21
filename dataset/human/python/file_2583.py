import itertools, math
d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]
ans = float('inf')
comb = list(itertools.product([0, 1], repeat=d))
for i in range(len(comb)):
    s = 0
    c = 0
    for j in range(d):
        if comb[i][j] == 1:
            s += pc[j][0] * (j + 1) * 100 + pc[j][1]
            c += pc[j][0]
    div = g - s
    if div <= 0:
        ans = min(ans, c)
        continue
    for j in range(d):
        tmpdiv = div
        tmpc = c
        if comb[i][j] == 0:
            cut = min(tmpdiv // math.ceil((j + 1) * 100), pc[j][0] - 1)
            tmpc += cut
            tmpdiv -= cut * (j + 1) * 100
            if tmpdiv <= 0:
                ans = min(ans, tmpc)
print(ans)
