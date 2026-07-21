import math
N = int(input())

def primary(x):
  D = {}
  for num in range(2, int(math.sqrt(x))+2):
    while x % num == 0:
      if num in D:
        D[num] += 1
      else:
        D.setdefault(num, 1)
      x = x // num
  if x > 1:
    D.setdefault(x, 1)
  if not D:
    return 0
  else:
    return D

primaryN = primary(N)
#print(primary(N))
a = 0
if N == 1:
  print(0)
elif primary(N) == 0:
  print(1)
else:
  for i in primaryN:
    j = 1
    while primaryN[i] > 0:
      primaryN[i] = primaryN[i] - j
      if primaryN[i] >= 0:
        a = a + 1
      j = j + 1
  print(a)
