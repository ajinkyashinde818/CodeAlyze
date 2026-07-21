import numpy as np
n = int(input())
a_ls = list(map(int, input().split()))

sum_ls = list(np.cumsum(a_ls))
sum_ls.insert(0,0)

ans = float('inf')
for i in range(1,n):
    su = sum_ls[i]
    ara = sum_ls[-1] - sum_ls[i]
    dif = abs(su-ara)
    if dif < ans:
        ans = dif

print(ans)
