import itertools
import math
D, G = map(int, raw_input().split())
p = [0]*D
c = [0]*D
for i in range(D):
  p[i], c[i] = map(int, raw_input().split())
r = sum(p)
for a in itertools.product([True, False], repeat=D):
  s = 0
  b = 0
  for i in range(D):
    if a[i]:
      s += p[i]
      pi = p[i]
      ci = c[i]
      b += (100*(i+1)*pi)+ci
  for i in range(D-1,-1,-1):
    if b>=G:
      break
    if not a[i]:
      d = min(p[i]-1, int(math.ceil(1.0*(G-b)/(100*(i+1)))))
      s += d
      b += 100*(i+1)*d
  if b>=G:
    r = min(r, s)
print r
