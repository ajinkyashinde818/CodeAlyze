import numpy as np
d, g = map(int, input().strip().split(' '))
p = [0] * d
c = [0] * d
num = []
for i in range(d):
  p[i], c[i] = map(int, input().strip().split(' '))
for j in range( 2**d ):
  csum = 0; n = 0; jpl = []
  for i in range(d):
    if j >= 2**(d-i-1):
      jp = 1
      j = j - 2**(d-i-1)
    else:
      jp = 0
      jpl.append(i)
    csum = csum + ( 100 * (i+1) * p[i] + c[i] ) * jp
    n = n + p[i] * jp
  if csum < g and jpl != []:
    i = max(jpl)
    remain = int(np.ceil( ( g - csum ) / ( 100 * (i+1) ) ))
    if remain < p[i]:
      n = n + remain
      num.append(n)
    else:
      pass
  else:
    num.append(n)
print(min(num))
