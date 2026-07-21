import numpy as np


n = int(input())
a = np.array(list(map(int, input().split())))
cumsum_a = a.cumsum()
sum_a = cumsum_a[-1]
ans = 2 * 10**9

for i in range(n-1):
    ans = min(ans, abs(sum_a - 2*cumsum_a[i]))

print(ans)
