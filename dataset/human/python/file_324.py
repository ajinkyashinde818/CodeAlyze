import numpy as np
n = int(input())
a = np.array(list(map(int, input().split())))

if 0 in a:
  b = list(map(abs, a))
  print(sum(b))
  
else:
  if (a[a<0].size % 2) == 0:
    b = list(map(abs, a))
    print(sum(b))
  else:
    b = list(map(abs, a))
    b = sorted(b)
    b.reverse()
    c = b.pop()
    print(sum(b)-c)
