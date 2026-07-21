import sys
from math import ceil
inputs = sys.stdin.readlines()

d, g = map(int, inputs[0].split())
P = list(map(int, map(lambda x: x.split()[0], inputs[1:])))
C = list(map(int, map(lambda x: x.split()[1], inputs[1:])))

ans = float('inf')
for bit in range(1 << d):
    count, total, rest = 0, 0, set(range(1, d+1))
    for i in range(d):
        if bit & (1 << i):
            total += P[i] * (i + 1) * 100 + C[i]
            count += P[i]
            rest.discard(i + 1)

    if total < g:
        use = max(rest)
        n = ceil((g - total) / (use * 100))
        if P[use-1]-1 < n:
            continue
        count += n
        total += n * use * 100
        
    if total >= g:
        ans = min(ans, count)
print(ans)
