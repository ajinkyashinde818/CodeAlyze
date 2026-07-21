import math

D, G = map(int, input().split())
p = [0] * D
c = [0] * D
ans = float('inf')
for i in range(D):
  p[i], c[i] = map(int, input().split())
for i in range(2 ** D):
  s = 0
  n = 0
  ma = -1
  for j in range(D):
    if ((i >> j) & 1) == 1:
      s += 100 * (j + 1) * p[j] + c[j]
      n += p[j]
    else:
      ma = j
  if s < G:
    m = math.ceil((G - s) / (100 * (ma + 1)))
    if m > p[ma]:
      continue
    else:
      n += m
  ans = min(ans, n)
print(ans)
