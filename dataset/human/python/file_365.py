import numpy as np

n = int(input())
a = np.array(list(map(int, input().split())))

b = np.sort(np.abs(a))
c = np.sum(a < 0)

if c % 2 == 0:
  total = np.sum(b)
else:
  total = np.sum(b[1:]) - b[0]
  
print(total)
