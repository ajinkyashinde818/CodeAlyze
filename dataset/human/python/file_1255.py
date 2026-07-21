import numpy as np
n=int(input())
a = [int(i) for i in input().split()]
ala = sum(a)
tmp = 0
ans = np.array([9999999999]*n)

for i in range(n-1):
 tmp += a[i]
 ala = ala - a[i]
 ans[i] = abs(tmp-ala)
print (min(ans))
