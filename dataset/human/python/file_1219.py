import numpy as np

n = int(input())
a = np.array(list(map(int,input().split())))

b = a[0]
c = a[1:].sum()
ans = abs(b - c)

for i in range(1, n-1):
  temp = a[i]
  b += temp
  c -= temp

  if ans > abs(b-c):
    ans = abs(b-c)
else:
  print(ans)
