d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]

import math
ans = float('inf')
for i in range(1 << d):
    point = 0
    solved = 0

    for j in range(d):
        if (i >> j) & 1:
            point += pc[j][1] + pc[j][0] * 100 * (j + 1)
            solved += pc[j][0]

    if point >= g:
        f = True
    else:
        f = False
        for j in reversed(range(d)):
            if not ((i >> j) & 1):
                if point + (j + 1) * 100 * (pc[j][0] - 1) >= g:
                    _solved = math.ceil((g - point) / ((j + 1) * 100))
                    solved += _solved
                    point += _solved * 100 * (j + 1)
                    f = True
                    break
                else:
                    _solved = pc[j][0] - 1
                    solved += _solved
                    point += _solved * 100 * (j + 1)

    if f:
        ans = min(ans, solved)

print(ans)
