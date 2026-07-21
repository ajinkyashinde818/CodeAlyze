import numpy as np
n = int(input())
a = np.array(input().split(),dtype=int)

mn = 0
ma = abs(a[0])
ans = 0
for i in a:
    if i < 0:
        mn += 1
    ans += abs(i)
    if abs(i) < ma:
        ma = abs(i)

if mn%2 == 1:
    ans -= ma*2

print(ans)
