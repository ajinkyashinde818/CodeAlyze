import math
from collections import defaultdict

def get_max_frequency(x):
  n = 1
  while True:
    if n*(n+1)/2 <= x and x < (n+1)*(n+2)/2:
      break
    n += 1
  return n

N = int(input())
divided = N
d = defaultdict(int)
ans = 0

for i in range(2, int(math.sqrt(N)//1)+1):
  while True:
    if divided%i == 0:
      divided //= i
      d[i] += 1
    else:
      break
d[divided] += 1
if 1 in d:
  del d[1]

for v in d.values():
  ans += get_max_frequency(v)

print(ans)
