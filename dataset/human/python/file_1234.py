n = int(input())
a = list(map(int, input().split()))

import itertools
accum = list(itertools.accumulate(a))

ans = float('inf')
for i in range(n-1):
    ans = min(ans, abs((accum[-1] - accum[i]) - accum[i]))
print(ans)
