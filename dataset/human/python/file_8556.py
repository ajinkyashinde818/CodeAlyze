k,n = map(int, input().split())

a = list(map(int, input().split()))

import numpy as np
a = np.array(a)

s = np.sort(a)
temae = 0
oku = 0
m = k
for i in range(n):
  if s[(i-1)%n] - s[i] < 0:
    c1 = k+s[(i-1)%n] - s[i]
  else:
    c1 = s[(i-1)%n] - s[i]
  if s[i] - s[(i+1)%n] > 0:
    c2= s[i] - s[(i+1)%n]
  else:
    c2 = k + s[i] - s[(i+1)%n]
  if m > c1:
    m = c1
  if m > c2:
    m = c2
print(m)
