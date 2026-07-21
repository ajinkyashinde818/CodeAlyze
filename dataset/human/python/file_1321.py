import numpy as np
n = int(input())
a = list(map(int, input().split()))
a_sum = np.cumsum(a)
sunuke = 0
res = 10**19
for i in range(n-1):
  sunuke += a[-i-1]
  if(abs(sunuke-a_sum[-i-2]) < res):
    res = abs(sunuke-a_sum[-i-2])
print(res)
