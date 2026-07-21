import numpy as np
import sys
 
n = int(input())
l = np.array([int(x) for x in input().split()])
ans = 0
if 0 in l:
  for i in range(n):
    ans += abs(l[i])
  print(ans)
  sys.exit()
m = abs(l[0])
p = 0
for i in range(n):
  if l[i] < 0:
    p += 1
  if m > abs(l[i]):
    m = abs(l[i])
for i in range(n):
  ans += abs(l[i])
if p % 2 == 0:
  print(ans)
else:
  print(ans - m*2)
