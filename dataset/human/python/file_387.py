import numpy as np
n = int(input())
a = [int(i) for i in input().split()]
count = 0
b = []
for i in a:
  if i <0:
    count += 1
  b.append(abs(i))
b.sort()
b = np.array(b)
if count % 2 ==0:
  print(b.sum())
else:
  print(b.sum()-b[0]*2)
